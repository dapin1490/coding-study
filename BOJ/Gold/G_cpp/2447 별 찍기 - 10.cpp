#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<string>> star; // 이차원 벡터
int n;

void pick(int n, int ix, int iy); // 별에 공백 찍기

int main()
{
	cin >> n;
	star.resize(n, vector<string>(n, "*")); // 전부 "*"로 초기화

	// 별에 공백 찍기
	pick(n, n / 3, n / 3);

	// 별 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << star[i][j];
		}
		cout << "\n";
	}

	return 0;
}

// 별에 공백 찍기
void pick(int n, int ix, int iy)
{
	// 가운데에 공백을 넣는다
	for (int i = 0; i < n / 3; i++) {
		for (int j = 0; j < n / 3; j++) {
			star[ix + i][iy + j] = " ";
		}
	}

	/*// 디버깅용 출력문
	cout << "pick(" << n << ", " << ix << ", " << iy << ")" << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << star[ix - n / 3 + i][iy - n / 3 + j];
		}
		cout << "\n";
	}*/

	if ((n / 3) < 3) // 다음 호출을 수행할 수 없다면 리턴 == "반환점"
		return;

	// 주변 8칸에 재귀 호출을 넣는다
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			/*// 디버깅용 출력문 : 다음 호출 출력
			string s = "next : " + to_string(n / 3) + ", " + to_string(n / 3 / 3 + i * n / 3) + ", " + to_string(n / 3 / 3 + j * n / 3);
			cout << s << "\n";*/
			if (i == 1 && j == 1) // 가운데 칸은 이미 공백이라 호출 불필요
				continue;
			pick(n / 3, ix - 2 * n / 9 + i * (n / 3), iy - n / 3 + n / 9 + j * (n / 3));
		}
	}
}
