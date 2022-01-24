#include <iostream>
#include <cmath>
using namespace std;

int q[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int n, cnt = 0;
void nq(int c);
bool check(int m);

int main()
{
	cin >> n;
	nq(0);
	cout << cnt << "\n";
	
	return 0;
}

void nq(int c) // c는 퀸을 놓을 행
{
	if (c == n)
	{
		cnt++;
		return;
	}
	
	for (int i = 0; i < n; i++) // i는 퀸을 놓을 열
	{
		q[c] = i; // 일단 놓기
		if (!check(c))
		{
			// 부적합 루트 : 다음 루트 검사
			continue;
		}
		// 적합 루트
		nq(c + 1); // 재귀 호출
		// N과 M 문제 시리즈 처럼 사용한 루트를 도로 지우지 않아도 된다.
		// 배열 값을 덮어쓰면 되기 때문
	}
}

bool check(int m) // 적합성 검사
{
	for (int i = 0; i < m; i++)
	{
		if (q[m] == q[i] || abs(q[m] - q[i]) == abs(m - i))
			return false;
	}
	
	return true;
}
