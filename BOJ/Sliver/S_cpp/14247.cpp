#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	long long total;
	int* tree;
	pair<int, int>* grow_tree;

	cin >> n;

	tree = new int[n];
	grow_tree = new pair<int, int>[n];
	for (int i = 0; i < n; i++)
		cin >> *(tree + i);

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		*(grow_tree + i) = pair<int, int>(temp, *(tree + i));
	}
	delete[] tree;

	sort(grow_tree, grow_tree + n, cmp);

	total = 0;
	for (int i = 0; i < n; i++)
		total += (*(grow_tree + i)).second + (*(grow_tree + i)).first * i;

	delete[] grow_tree;

	cout << total;

	return 0;
}
