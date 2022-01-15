#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int count = 0;
	string ar[8] = {"dz=", "c=", "c-", "d-", "lj", "nj", "s=", "z="};

	for (int i = 0; i < 8; i++)
	{
		while (true)
		{
			int n = s.find(ar[i]);

			if (n == -1)
				break;

			s.replace(n, ar[i].length(), "#");
		}
	}

	cout << s.length();

	
	return 0;
}
