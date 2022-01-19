#include <iostream>
using namespace std;

bool sosu(int n);

int main()
{
	int count = 0;
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		if (sosu(n))
			count++;
	}

	cout << count;
	
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
