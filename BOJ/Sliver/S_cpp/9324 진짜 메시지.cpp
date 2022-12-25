#include <iostream>
#include <string>
using namespace std;

bool realmsg(string s);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;

		if (realmsg(s))
			cout << "OK\n";
		else
			cout << "FAKE\n";
	}

	return 0;
}

bool realmsg(string s)
{
	int ar[26] = { 0 };
	char key;
	bool check = false;
	int len = s.length();

	for (int i = 0; i < len; i++) {
		int idx = int(s.at(i) - 'A');
		ar[idx]++;

		if (ar[idx] == 3 && !check) {
			key = s.at(i);
			check = true;
			continue;
		}

		if (check) {
			if (key != s.at(i)) {
				return false;
			}
			ar[int(key - 'A')] = 0;
			check = false;
		}
	}

	if (check)
		return false;
	else
		return true;
}
