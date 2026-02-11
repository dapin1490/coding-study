#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <climits>
using namespace std;

int goal, len;
vector<int> valid_btns;
vector<int> order;
int min_dist = INT_MAX;

void make_permute(int now, int len) {
	if (now == len) {
		int temp = 0;
		for (int i = 0; i < len; i++)
			temp = temp * 10 + valid_btns[order[i]];
		temp = goal - temp;
		if (abs(temp) < abs(min_dist) || (abs(temp) == abs(min_dist) && temp > min_dist))
			min_dist = temp;
		return;
	}

	for (int i = 0; i < valid_btns.size(); i++) {
		order[now] = i;
		make_permute(now + 1, len);
	}
}

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, temp_int;
	set<int> invalid_btns;
	pair<int, int> buffer;

	cin >> goal >> n;

	len = floor(log10(max(1, goal))) + 1;
	order.resize(len + 1);

	for (int i = 0; i < n; i++) {
		cin >> temp_int;
		invalid_btns.emplace(temp_int);
	}

	for (int i = 0; i <= 9; i++) {
		if (invalid_btns.find(i) == invalid_btns.end())
			valid_btns.emplace_back(i);
	}

	if (len - 1 > 0)
		make_permute(0, len - 1);
	make_permute(0, len);
	make_permute(0, len + 1);

	if (min_dist != INT_MAX) {
		temp_int = abs(min_dist) + floor(log10(max(1, goal - min_dist))) + 1;
		if (abs(goal - 100) < temp_int) {
			temp_int = abs(goal - 100);
		}
	}
	else {
		temp_int = abs(goal - 100);
	}

	cout << temp_int << "\n";

	return 0;
}