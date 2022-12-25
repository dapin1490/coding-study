#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 9012 괄호
string VPS(string s);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	string s;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> s;
		cout << VPS(s) << "\n";
	}

	return 0;
}

string VPS(string s)
{
	vector<string> v;
	bool ok = true;

	for (int i = 0; i < s.length(); i++) {
		switch (s.at(i)) {
		case '(':
			v.push_back("(");
			break;
		case ')':
			if (v.empty())
				ok = false;
			else
				v.pop_back();
			break;
		}
	}

	if (ok && v.empty())
		return "YES";
	else
		return "NO";
}
