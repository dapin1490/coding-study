#include <iostream>
#include <string>
using namespace std;

string bod[51]; // 가로줄 하나씩 저장
string cutb[9]; // 자른 보드
int n, m;
char key, value;
int mincount = 33, cnt = 0;

int main()
{
	// 입력을 받아서 한 줄씩 string으로 배열에 저장한다
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> bod[i];

	// 자를 수 있는 최대 횟수만큼 반복
	int w = m - 8 + 1; // 가로
	int h = n - 8 + 1; // 세로
	for (int i = 0; i < h * w; i++)	{
		// cout << "\n" << "cutted board " << i + 1 << "\n";
		// 보드 자르기
		for (int j = i / w; j < (i / w) + 8; j++) { // 위에서 몇 번째 줄부터 자를지
			cutb[j - i / w] = bod[j].substr(i % w, 8); // 왼쪽에서 몇 번째 글자부터 자를지
			// cout << cutb[j - i / w] << "\n";
		}

		// 임시로 자른 보드에서 바꿔야 할 칸의 수를 셈
		// 첫 칸이 검은색
		cnt = 0;
		key = 'B';
		for (int a = 0; a < 8; a++) {
			for (int b = 0; b < 8; b++) {
				value = cutb[a].at(b);
				// cout << "start B : (" << a + 1 << ", " << b + 1 << ") cnt = ";
				switch (key)
				{
				case 'W':
					if (key != value)
						cnt++;
					key = 'B';
					// cout << cnt << "\n";
					break;
				case 'B':
					if (key != value)
						cnt++;
					key = 'W';
					// cout << cnt << "\n";
					break;
				}
			}
			// 줄이 바뀔 때는 색이 바뀌지 않음
			if (key == 'W')
				key = 'B';
			else
				key = 'W';

			if (mincount < cnt) // 최솟값이 아니라면 중단
				break;
		}

		if (mincount > cnt)
			mincount = cnt;

		// 첫 칸이 흰색
		cnt = 0;
		key = 'W';
		for (int a = 0; a < 8; a++) {
			for (int b = 0; b < 8; b++) {
				value = cutb[a].at(b);
				// cout << "start W : (" << a + 1 << ", " << b + 1 << ") cnt = ";
				switch (key)
				{
				case 'W':
					if (key != value)
						cnt++;
					key = 'B';
					// cout << cnt << "\n";
					break;
				case 'B':
					if (key != value)
						cnt++;
					key = 'W';
					// cout << cnt << "\n";
					break;
				}
			}
			// 줄이 바뀔 때는 색이 바뀌지 않음
			if (key == 'W')
				key = 'B';
			else
				key = 'W';

			if (mincount < cnt) // 최솟값이 아니라면 중단
				break;
		}

		if (mincount > cnt)
			mincount = cnt;

		cnt = 0;
	}

	cout << mincount;

	return 0;
}
