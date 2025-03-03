#include <iostream>
using namespace std;

int kipa_step(int num);
int kipa(int num);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;

	cin >> n;

	cout << kipa(n);

	return 0;
}

int kipa_step(int num)
{
	int res = 1;

	while (num > 0) {
		res *= (num % 10);
		num /= 10;
	}

	return res;
}

int kipa(int num)
{
	int cnt = 0;

	if (num < 10)
		return cnt;

	while (num > 9) {
		num = kipa_step(num);
		cnt++;
	}

	return cnt;
}
