#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string num;
	long long ans = 0, n;

	cin >> num;
	n = stoi(num);

	switch (num.length())
	{
	case 9: ans += 9;
	case 8: ans += (n >= 100000000) ? 90000000 * 8 : (n - 9999999) * 8;
	case 7: ans += (n >= 10000000) ? 9000000 * 7 : (n - 999999) * 7;
	case 6: ans += (n >= 1000000) ? 900000 * 6 : (n - 99999) * 6;
	case 5: ans += (n >= 100000) ? 90000 * 5 : (n - 9999) * 5;
	case 4: ans += (n >= 10000) ? 9000 * 4 : (n - 999) * 4;
	case 3: ans += (n >= 1000) ? 900 * 3 : (n - 99) * 3;
	case 2: ans += (n >= 100) ? 90 * 2 : (n - 9) * 2;
	case 1: ans += (n >= 10) ? 9 : n;
	}

	cout << ans;

	return 0;
}
