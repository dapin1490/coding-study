#include <iostream>
using namespace std;

int fly(int start, int end);

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << fly(a, b) << "\n";
	}
	

	return 0;
}

int fly(int start, int end)
{
	int len = end - start;
	int count = 0;
	int distance = 1;

	while (true)
	{
		if (len == 0)
			break;

		if (len >= distance * 2)
		{
			len -= distance * 2;
			count += 2;
			distance++;
		}
		else if (len >= (distance * 2 - 1) && distance != 1)
		{
			len -= (distance * 2 - 1);
			count += 2;
		}
		else if (len == distance)
		{
			len -= distance;
			count++;
		}
		else
			distance--;
	}

	return count;
}
