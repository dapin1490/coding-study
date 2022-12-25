#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s, s16, ans = "";
	int up = 0;

	cin >> s;

	s16 = s + "0000"; // 원래 수의 16배
	s = "0000" + s; // 이걸 더하면 17배가 됨

	for (int i = s.length() - 1; i >= 0; i--) {
		int a = int(s.at(i) - '0');
		int b = int(s16.at(i) - '0');

		switch (a + b + up)
		{
		case 3:
			ans = "1" + ans; up = 1; break;
		case 2:
			ans = "0" + ans; up = 1; break;
		case 1:
			ans = "1" + ans; up = 0; break;
		case 0:
			ans = "0" + ans; up = 0; break;
		}
	}

	if (up == 0)
		cout << ans;
	else
		cout << "1" << ans;

	return 0;
}
