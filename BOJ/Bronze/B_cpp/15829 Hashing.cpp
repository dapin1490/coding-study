#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	const long long R = 31;
	const long long M = 1234567891;

	int l;
	string s;
	long long ans = 0;
	cin >> l >> s;

	for (int i = l - 1; i > 0; i--) {
		ans = (ans + int(s.at(i)) - int('a') + 1) * R;
		ans %= M;
	}

	ans = ans + int(s.at(0)) - int('a') + 1;
	ans %= M;

	cout << ans;

	return 0;
}
