#include <iostream>
using namespace std;

long long plus();
long long minus();
long long multi();
long long divi();

long long a, b, last;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	last = 1;
	int n;
	char c;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> c >> b;

		switch (c) {
		case '+':
			cout << ::plus() << "\n";
			break;
		case '-':
			cout << ::minus() << "\n";
			break;
		case '*':
			cout << ::multi() << "\n";
			break;
		case '/':
			cout << ::divi() << "\n";
			break;
		}
	}

	return 0;
}

long long plus()
{
	last = a + b - last;
	return last;
}

long long minus()
{
	last = (a - b) * last;
	return last;
}

long long multi()
{
	last = (a * b) * (a * b);
	return last;
}

long long divi()
{
	last = ((a % 2 == 0) ? a / 2 : (a + 1) / 2);
	return last;
}
