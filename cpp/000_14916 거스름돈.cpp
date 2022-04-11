#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, c2, c5;

	cin >> n;

	c2 = 0;
	c5 = 0;
	while (true) {
		if (n % 5 == 0) {
			c5 += n / 5;
			cout << c2 + c5;
			return 0;
		}
		else if (n < 0) {
			cout << -1;
			return 0;
		}

		n -= 2;
		c2++;
	}
}
