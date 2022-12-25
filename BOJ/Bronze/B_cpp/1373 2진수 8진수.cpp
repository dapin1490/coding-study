#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string ans;
	string s;
	int len, idx;
	cin >> s;

	if (s.length() % 3 != 0) {
		for (int i = 0; i < s.length() % 3; i++)
			s = "0" + s;
	}

	len = s.length() / 3;
	idx = 0;
	for (int i = 0; i < len; i++) {
		string t = s.substr(idx, 3);
		idx += 3;

		ans += to_string(stoi(t, nullptr, 2));
	}

	cout << ans;

	return 0;
}
