#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, dig, cnt;
	bool flag = false;
	cin >> n;

	dig = 1, cnt = 1;
	while (dig <= n && cnt <= 10) {
		dig *= 10;
		cnt++;
	}
	cnt--;

	for (int i = 1; i < cnt; i++) {
		dig = n;
		int a = 1, b = 1;
		
		for (int j = cnt; j >= i + 1; j--) {
			b *= (dig % 10);
			dig /= 10;
		}
		for (int j = i; j > 0; j--) {
			a *= (dig % 10);
			dig /= 10;
		}

		if (a == b) {
			flag = true;
			break;
		}
	}

	cout << ((flag) ? "YES" : "NO");

	return 0;
}
