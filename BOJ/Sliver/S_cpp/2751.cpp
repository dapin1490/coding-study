#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	vector<int> v;
	int x = 0;

	for (int i = 0; i < t; i++) {
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < t; i++) {
		cout << v[i] << "\n";
	}

	return 0;
}
