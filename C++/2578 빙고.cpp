#include <iostream>
using namespace std;

// 빙고?
bool bingo();

int bin[25] = { 0 };
bool go[5][5] = { {0} };
int cnt = 0;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> n;
			bin[n - 1] = i * 10 + j;
		}
	}

	int x, y;
	for (int i = 1; i <= 5; i++) {
		cin >> n;
		x = bin[n - 1] / 10;
		y = bin[n - 1] % 10;
		go[x][y] = 1;
	}
	for (int i = 6; i <= 25; i++) {
		cin >> n;
		x = bin[n - 1] / 10;
		y = bin[n - 1] % 10;
		go[x][y] = 1;
		if (bingo()) {
			cout << i;
			break;
		}
	}

	return 0;
}

// 빙고?
bool bingo()
{
	int cnt = 0;

	// 가로 빙고
	for (int i = 0; i < 5; i++) {
		bool flag = true;
		for (int j = 0; j < 5; j++) {
			if (!go[i][j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cnt++;
		}
	}

	// 세로 빙고
	for (int i = 0; i < 5; i++) {
		bool flag = true;
		for (int j = 0; j < 5; j++) {
			if (!go[j][i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cnt++;
		}
	}

	// 대각선 빙고
	bool reslash = true;
	bool slash = true;
	for (int i = 0; i < 5; i++) {
		if (!go[i][i]) {
			reslash = false;
		}
		if (!go[i][4 - i]) {
			slash = false;
		}
	}
	if (reslash)
		cnt++;
	if (slash)
		cnt++;

	if (cnt >= 3)
		return true;
	else
		return false;
}
