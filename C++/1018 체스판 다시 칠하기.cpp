#include <iostream>
#include <string>
using namespace std;

string bod[51]; // 주어진 체스판 가로줄 하나씩 저장.
// 배열의 크기는 바꿀 수 없고 변수를 사용할 수도 없기 때문에 주어진 입력의 최댓값에 맞춘다. 1은 여분이다.
string cutb[9]; // 미니 체스판을 저장할 배열. 원래 미니 체스판은 8줄이지만 1은 여분이다.
int n, m; // 주어진 체스판의 크기
char key, value; // 체스판의 색을 검사할 때 사용
// key는 원래 있어야 할 색, value는 미니 체스판에 실제 있는 색
int mincount = 33, cnt = 0; // 답으로 출력할 mincount와 미니 체스판마다 개수를 셀 cnt
// 체스판이 단색이라고 해도 최대 32칸을 칠할 수 있기 때문에 mincount의 초기값은 33으로 정했다.
// 사실 몇으로 하든 충분히 크기만 하다면 상관 없다.

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
		// cout << "\n" << "cutted board " << i + 1 << "\n"; // 디버깅용 출력문. 이번 미니 체스판이 몇 번째인지 출력한다.
		// 체스판 자르기
		for (int j = i / w; j < (i / w) + 8; j++) { // 위에서 몇 번째 줄부터 자를지
			cutb[j - i / w] = bod[j].substr(i % w, 8); // 왼쪽에서 몇 번째 글자부터 자를지
			// cout << cutb[j - i / w] << "\n"; // 디버깅용 출력문. 잘라낸 미니 체스판을 가로로 한 줄씩 출력한다.
		}

		// 미니 체스판에서 칠해야 할 칸의 수를 셈
		// 첫 칸이 검은색일 경우
		cnt = 0;
		key = 'B';
		for (int a = 0; a < 8; a++) {
			for (int b = 0; b < 8; b++) {
				value = cutb[a].at(b);
				// cout << "start B : (" << a + 1 << ", " << b + 1 << ") cnt = "; // 디버깅용 출력문. 이번에 검사하는 칸의 인덱스를 출력한다.
				switch (key) // 지금 검사하는 칸에 칠해져 있어야 하는 색을 기준으로
				{
				case 'W':
					if (key != value) // 잘못된 색이 칠해져 있다면
						cnt++;
					key = 'B'; // 다음 검사를 위한 초기화
					// cout << cnt << "\n"; // 디버깅용 출력문. 이번 검사로 업데이트한 cnt를 출력한다.
					break;
				case 'B':
					if (key != value) // 잘못된 색이 칠해져 있다면
						cnt++;
					key = 'W'; // 다음 검사를 위한 초기화
					// cout << cnt << "\n"; // 디버깅용 출력문. 이번 검사로 업데이트한 cnt를 출력한다.
					break;
				}
			}
			// 줄이 바뀔 때는 색이 바뀌지 않음
			if (key == 'W') // 직전의 반복에서 다음 검사를 위한 초기화가 되었을 것이므로 다시 초기화한다.
				key = 'B';
			else
				key = 'W';

			if (mincount < cnt) // cnt가 최솟값이 아니라면 중단
				break;
		}

		if (mincount > cnt) // mincount 업데이트
			mincount = cnt;

		// 첫 칸이 흰색일 경우
		// key = 'W'로 초기화하고 시작한다는 점을 제외하면 첫 칸이 검은색일 경우와 완전히 똑같으므로 주석은 추가하지 않았다.
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

	cout << mincount; // 답 출력

	return 0;
}
