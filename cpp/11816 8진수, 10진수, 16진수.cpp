// (1) string 라이브러리 함수 사용
// (2) 함수 구현

// (1) string 라이브러리 함수 사용
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;

	int base = 10;
	if (s.find("0x") != string::npos) {
		// 16진수
		base = 16;
	}
	else if (s.at(0) == '0') {
		// 8진수
		base = 8;
	}

	cout << stoi(s, nullptr, base);

	return 0;
}


/*
// (2) 함수 구현
#include <iostream>
#include <string>
using namespace std;

// 8진수 번역
int eight(string n);
// 16진수 번역
int six(string n);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;

	int base = 10;
	if (s.find("0x") != string::npos) {
		// 16진수
		base = 16;
	}
	else if (s.at(0) == '0') {
		// 8진수
		base = 8;
	}

	switch (base)
	{
	case 10:
		cout << s;
		break;
	case 8:
		cout << eight(s);
		break;
	case 16:
		cout << six(s);
		break;
	}

	return 0;
}

// 8진수 번역
int eight(string n)
{
	int ans = 0;
	for (int i = 1; i < n.length(); i++) {
		ans = (ans + int(n.at(i) - '0')) * 8;
	}

	return ans / 8;
}

// 16진수 번역
int six(string n)
{
	int ans = 0;
	for (int i = 2; i < n.length(); i++) {
		switch (n.at(i))
		{
		case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
			ans = (ans + int(n.at(i) - 'a' + 10)) * 16;
			break;
		default:
			ans = (ans + int(n.at(i) - '0')) * 16;
		}
	}

	return ans / 16;
}
*/
