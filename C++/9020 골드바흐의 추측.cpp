#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> v(10001); // 소수 여부 저장
string gold(int n);

int main()
{
	v[0] = 1; // 소수가 아니니까 1로 초기화
	v[1] = 1;

	// 에라토스테네스의 체
	for (int i = 2; i < 10000 + 1; i++)
	{
		for (int j = 2 * i; j < 10000 + 1; j += i)
		{
			if (v[j] == 0)
				v[j] = 1;
		}
	}
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int num;
		cin >> num;
		cout << gold(num) << "\n";
	}

	return 0;
}

string gold(int n)
{
	int idx = n / 2;
	int id2 = n - idx;
	while (true)
	{
		if (v[idx] == 0 && v[id2] == 0)
			break;
		else
		{
			idx--;
			id2++;
		}
	}

	string ans = to_string(idx) + " " + to_string(id2);
	return ans;
}
