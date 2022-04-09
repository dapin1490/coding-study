#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b) { return a > b; }
int gap(vector<int> v);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int s, a;
		vector<int> v;

		cin >> s;

		for (int j = 0; j < s; j++) {
			cin >> a;
			v.push_back(a);
		}

		sort(v.begin(), v.end(), comp);

		cout << "Class " << i << "\nMax " << v.front() << ", Min " << v.back() 
			<< ", Largest gap " << gap(v) << "\n";
	}

	return 0;
}

int gap(vector<int> v)
{
	int a, maxi;

	maxi = v[0] - v[1];
	for (int i = 2; i < v.size(); i++) {
		a = v[i - 1] - v[i];

		if (a > maxi)
			maxi = a;
	}

	return maxi;
}
