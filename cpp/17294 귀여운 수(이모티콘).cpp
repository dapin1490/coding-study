#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;

	if (s.length() <= 2) {
		cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
		return 0;
	}

	bool flag = true;
	int d = int(s.at(1) - '0') - int(s.at(0) - '0');
	for (int i = 2; i < s.length(); i++) {
		int v = int(s.at(i) - '0') - int(s.at(i - 1) - '0');
		if (v != d) {
			flag = false;
			break;
		}
	}

	if (flag)
		cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
	else
		cout << "흥칫뿡!! <(￣ ﹌ ￣)>";

	return 0;
}
