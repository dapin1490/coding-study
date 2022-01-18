#include <iostream>
using namespace std;

int main()
{
	int sugar = 0;
	int n;
	cin >> n;

	while (true)
	{
		if (n % 5 == 0 && n >= 0)
			break;
		else if (n < 0)
		{
			cout << -1;
			return 0;
		}

		n -= 3;
		sugar++;
	}

	cout << sugar + (n / 5);

	
	return 0;
}
