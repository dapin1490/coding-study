#include <iostream>
using namespace std;

int hansu(int n);

int main()
{
	int n;
	cin >> n;
	cout << hansu(n);

	return 0;
}

int hansu(int n)
{
	if (n < 100) // 100보다 작으면 그대로 반환
		return n;

	// 100 이상
	int count = 99; // 1부터 99까지 포함

	for (int i = 100; i <= n; i++)
	{
		int one = i % 10; // 일의 자리
		int ten = (i % 100) / 10; // 십의 자리
		int hund = i / 100; // 백의 자리

		if ((ten - one) == (hund - ten))
			count++;
	}

	return count;
}