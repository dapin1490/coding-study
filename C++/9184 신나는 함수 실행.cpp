// 동적 계획법

#include <iostream>
using namespace std;

int a, b, c;
int me[102][102][102];

int w(int a, int b, int c);

int main()
{
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 and b == -1 and c == -1)
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
	}

	return 0;
}

int w(int a, int b, int c)
{
	if (me[50 + a][50 + b][50 + c] != 0) {
		return me[50 + a][50 + b][50 + c];
	}

	if (a <= 0 or b <= 0 or c <= 0) {
		int ans = 1;
		me[50 + a][50 + b][50 + c] = ans;
		return ans;
	}
	else if (a > 20 or b > 20 or c > 20) {
		int ans = w(20, 20, 20);
		me[50 + a][50 + b][50 + c] = ans;
		return ans;
	}
	else if (a < b and b < c) {
		int ans = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		me[50 + a][50 + b][50 + c] = ans;
		return ans;
	}
	else {
		int ans = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
		me[50 + a][50 + b][50 + c] = ans;
		return ans;
	}
}
