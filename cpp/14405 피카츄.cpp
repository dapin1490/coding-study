#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;

	int count = 0;
	string ar[8] = { "pi", "ka", "chu" };

	for (int i = 0; i < 3; i++)
	{
		while (true)
		{
			int n = s.find(ar[i]);

			if (n == -1)
				break;

			s.replace(n, ar[i].length(), "#");
		}
	}

	bool p = true;
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) != '#') {
			p = false;
			break;
		}
	}

	if (p)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
