#include <iostream>
using namespace std;

int a[32]; // 원래 수
int b[32]; // 보수

int main()
{
	int up = 1; // 덧셈 연산을 할 때 올릴 수
	int cnt = 0; // 카운트
	int n;
	cin >> n;

	// 원래 수를 이진수로 바꿔 a[]에 저장하면서 b[]에 반대 값 저장
	for (int i = 0; i < 32; i++)
	{
		a[i] = n % 2;
		b[i] = 1 - a[i];
		n /= 2;
	}

	// 보수 계산
	for (int i = 0; i < 32; i++)
	{
		b[i] += up; // up의 초기값이 1이기 때문에 보수 연산으로 더해지는 1과 같음
		switch (b[i])
		{
		case 3:
			up = 1;
			b[i] = 1;
			break;
		case 2:
			up = 1;
			b[i] = 0;
			break;
		default:
			up = 0;
		}
	}

	// 다른 수 세기
	for (int i = 0; i < 32; i++)
	{
		if (a[i] != b[i])
			cnt++;
	}

	cout << cnt;
	
	return 0;
}
