#include <iostream>
using namespace std;

int main()
{
	int room[15][15]; // 층 수 * 방 수
	for (int i = 0; i < 15; i++)
	{
		room[0][i] = i;
		room[i][0] = 0;
	}
	
	for (int i = 1; i < 15; i++) // 층 수
	{
		for (int j = 0; j < 15; j++) // 방 수
		{
			int  m = 1;
			room[i][j] = 0;
			while (m <= j)
			{
				room[i][j] += room[i - 1][m];
				m++;
			}
		}
	}

	int t; // 테스트 케이스
	cin >> t;

	for (int ii = 0; ii < t; ii++)
	{
		int k, n;
		cin >> k >> n;

		cout << room[k][n] << "\n";
	}
	

	return 0;
}
