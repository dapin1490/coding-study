#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// 필요한 감독관 수 구하기. s는 학생 수
long long hire(int p);

vector<int> testplace; // 전체 시험장별 사람 수
int b, c; // 총감독관, 부감독관의 감시 용량
long long ans = 0; // 답

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, a; // 시험장 수, 각 시험장 사람 수
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a;
		testplace.push_back(a);
	}
	cin >> b >> c;

	for (int i = 0; i < t; i++) {
		ans += hire(testplace[i]);
	}

	cout << ans;

	return 0;
}

// 필요한 감독관 수 구하기
long long hire(int p)
{
	if (p > b) {
		int cnt = 1;
		p -= b;
		cnt += p / c;
		if (p % c != 0)
			cnt++;
		return cnt;
	}
	else {
		return 1;
	}
}
