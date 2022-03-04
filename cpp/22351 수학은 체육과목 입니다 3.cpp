#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;

	int start = 0, n = 0;

	for (int i = 1; i <= s.length(); i++) { // 시작 숫자 찾기
		start = stoi(s.substr(0, i));
		string one = to_string(start);
		if (one == s) { // 시작 숫자와 끝 숫자가 같을 때
			cout << start << " " << start;
			return 0;
		}

		n = start + 1;
		while (true) {
			if (one.length() >= s.length())
				break;

			one += to_string(n); n++;
		}

		if (one == s) {
			n--;
			break;
		}
	}

	cout << start << " " << n;

	return 0;
}
