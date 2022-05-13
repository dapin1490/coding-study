#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	int ans;

	cin >> n;

	ans = 1;
	while (n > 1) {
		ans *= 2;
		n = n / 2;
	}

	cout << ans;

	return 0;
}
