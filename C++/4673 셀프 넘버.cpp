#include <iostream>
#include <vector>
#include <string>
using namespace std;

int d(int n);

int main()
{
	vector<int> v(10001);
	int index = 1;

	while (index <= 10000)
	{
		if (v.at(index) == 0)
		{
			int i = index;
			while (true)
			{
				int n = d(i);

				if (n > 10000)
					break;

				v.at(n)++;
				i = n;
			}
		}
		
		index++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		if (v.at(i) == 0)
			cout << i << "\n";
	}


	return 0;
}

int d(int n)
{
	string s = to_string(n);

	for (int i = 0; i < s.length(); i++)
		n = n + static_cast<int>(s.at(i) - '0');

	return n;
}
