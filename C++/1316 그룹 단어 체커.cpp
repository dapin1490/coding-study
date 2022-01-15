#include <iostream>
#include <string>
using namespace std;

// 그룹 단어 판별 함수
bool word(string s);

int main()
{
	int n;
	cin >> n;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		if (word(s))
			count++;
	}

	cout << count;

	
	return 0;
}

// 그룹 단어 판별 함수
bool word(string s)
{
	int len = s.length();
	bool change = false;
	
	for (int i = 0; i < len; i++)
	{
		char key = s.at(i);

		for (int j = i + 1; j < len; j++)
		{
			if (s.at(j) != key)
			{
				if (!change)
					i = j - 1;
				change = true;
			}

			if (change && s.at(j) == key)
				return false;
		}

		change = false;
	}

	return true;
}
