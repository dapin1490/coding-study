#include <iostream>
using namespace std;

bool sosu(int n);

int main()
{
	int sum = 0; // 소수의 합
	int min = 10001; // 최솟값
	int m, n;
	cin >> m >> n;

	for (int i = m; i <= n; i++)
	{
		if (sosu(i))
		{
			sum += i;
			if (i < min)
				min = i;
		}
	}

	if (sum == 0)
		cout << -1;
	else
		cout << sum << "\n" << min;
	
	return 0;
}

bool sosu(int n)
{
	if (n < 2)
		return false;

	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}
