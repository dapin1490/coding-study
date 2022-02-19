#include <iostream>
#include <vector>
using namespace std;

vector<int> v(1000001); // 소수 여부 저장

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	v[0] = 1; // 소수가 아니니까 1로 초기화
	v[1] = 1;

	// 에라토스테네스의 체
	for (int i = 2; i < 1000000 / 2 + 1; i++)
	{
		for (int j = 2 * i; j < 1000000 + 1; j += i)
			v[j] = 1;
	}

	while (true)
	{
		int n;
		cin >> n;

		if (n == 0)
			break;

		int idx = v[3];
		int id2 = n - idx;
		while (true)
		{
			if ((v[idx] == 0 && v[id2] == 0) || idx > id2)
				break;
			else
			{
				idx++;
				id2--;
			}
		}

		if (idx <= id2)
			cout << n << " = " << idx << " + " << id2 << "\n";
		else
			cout << "Goldbach's conjecture is wrong.\n";
	}

	return 0;
}
