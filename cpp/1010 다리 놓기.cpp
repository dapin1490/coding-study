#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int pas[31][31] = { 0 };
	int t;
	int x, y;

	for (int i = 0; i < 31; i++) {
		pas[i][0] = 1;
		pas[i][i] = 1;
	}

	for (int i = 1; i < 31; i++) {
		for (int j = 1; j <= i; j++) {
			pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
		}
	}

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> x >> y;

		cout << pas[y][x] << "\n";
	}

	return 0;
}
