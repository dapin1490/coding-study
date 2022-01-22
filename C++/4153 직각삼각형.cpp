#include <iostream>
#include <cmath>
using namespace std;

int tri[] = { 1, 1, 1 };
int a, b, c;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		cin >> tri[0] >> tri[1] >> tri[2];
		if (tri[0] == 0)
			break;

		if (tri[0] > tri[1])
		{
			if (tri[0] > tri[2])
				c = tri[0], a = tri[1], b = tri[2];
			else
				c = tri[2], a = tri[1], b = tri[0];
		}
		else
		{
			if (tri[1] > tri[2])
				c = tri[1], a = tri[0], b = tri[2];
			else
				c = tri[2], a = tri[1], b = tri[0];
		}

		if (pow(c, 2) == (pow(a, 2) + pow(b, 2)))
			cout << "right" << "\n";
		else
			cout << "wrong" << "\n";
	}

	return 0;
}
