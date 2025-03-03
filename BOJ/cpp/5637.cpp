#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;

	while (!cin.eof()) {
		string t;
		getline(cin, t);
		s += t;
	}

	string tempword, word;
	int maxlen = 0;

	for (int i = 0; i < s.length(); i++) {
		char key = s.at(i);
		if ((isalpha(key)) || key == '-') {
			tempword += tolower(key);
		}
		else {
			if (tempword.length() > maxlen) {
				word = tempword;
				maxlen = word.length();
			}
			tempword.clear();
		}

		if (i >= s.length() - 1 && tempword.length() > maxlen) {
			word = tempword;
			maxlen = word.length();
			tempword.clear();
		}
	}

	cout << word;

	return 0;
}
