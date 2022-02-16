#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	vector<int> v;
	for (int i = 0; i < s.length(); i++) {
		int a = s.at(i) - '0';
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v.at(i);
	}
	
	return 0;
}
