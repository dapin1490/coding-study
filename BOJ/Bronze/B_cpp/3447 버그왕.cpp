#include <iostream>
#include <string>
using namespace std;

int main() {
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (true) {
		if (cin.eof() == true)
			break;

		string s;
		getline(cin, s);

		while (true) {
			int idx = s.find("BUG");

			if (idx == -1)
				break;

			s.erase(idx, 3);
		}

		cout << s << "\n";
	}

	return 0;
}
