#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v;

int main() {
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	string tt;
	getline(cin, tt);
	t = stoi(tt);

	for (int i = 1; i <= t; i++) {
		string s;
		getline(cin, s);
		s += ' ';

		while (true) {
			int idx = s.find(" ");

			if (s.length() < 1)
				break;

			string subs = s.substr(0, idx);
			v.push_back(subs);
			s.erase(0, idx + 1);
		}

		cout << "Case #" << i << ":";
		for (int j = v.size() - 1; j >= 0; j--) {
			cout << " " << v[j];
		}
		cout << "\n";
		v.clear();
	}

	return 0;
}
