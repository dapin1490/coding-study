#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v1; // 더 긴 수
	vector<int> v2; // 짧은 수
	vector<int> ans; // 답
	int up = 0; // 올림 수

	string a, b;
	cin >> a >> b;

	if (a.length() < b.length())
	{
		string temp = a;
		a = b;
		b = temp;
	}

	for (int i = a.length() - 1; i >= 0; i--)
	{
		v1.push_back(static_cast<int>(a.at(i) - '0'));
		if (i < b.length())
			v2.push_back(static_cast<int>(b.at(i) - '0'));
	}

	for (int i = 0; i < a.length() - b.length(); i++)
	{
		v2.push_back(0);
	}

	for (int i = 0; i < a.length(); i++)
	{
		int n = v1.at(i) + v2.at(i) + up;
		up = 0;
		if (n >= 10)
		{
			n -= 10;
			up = 1;
		}

		ans.push_back(n);
	}

	if (up == 1)
		ans.push_back(up);

	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans.at(i);

	
	return 0;
}
