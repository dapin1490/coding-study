#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		bool trian = false;
		if (a >= b) {
			if (a > c) { // a가 빗변
				trian = a * a == b * b + c * c;
			}
			else if (c > a) { // c가 빗변
				trian = c * c == b * b + a * a;
			}
		}
		else {
			if (b > c) { // b가 빗변
				trian = b * b == a * a + c * c;
			}
			else if (c > b) { // c가 빗변
				trian = c * c == b * b + a * a;
			}
		}

		cout << "Scenario #" << i << ":\n";
		if (trian) {
			cout << "yes\n\n";
		}
		else {
			cout << "no\n\n";
		}
	}

	return 0;
}
