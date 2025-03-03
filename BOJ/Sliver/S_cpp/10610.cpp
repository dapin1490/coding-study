#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	
	vector<int> v;
	int a = 0;
	for (int i = 0; i < s.length(); i++) {
		v.push_back(static_cast<int>(s.at(i) - '0'));
		a += v.at(i);
	}

	sort(v.begin(), v.end());

	if (a % 3 == 0 && v.at(0) == 0) {
		for (int i = v.size() - 1; i >= 0; i--) {
			cout << v.at(i);
		}
	}
	else
		cout << -1;

	return 0;
}
