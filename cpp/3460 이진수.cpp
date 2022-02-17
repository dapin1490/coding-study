#include <iostream>
using namespace std;

// 이진수로 바꿔서 1 인덱스만 출력하기
void dropTheBeat(int n);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		dropTheBeat(n);
		cout << "\n";
	}

	return 0;
}

// 이진수로 바꿔서 1 인덱스만 출력하기
void dropTheBeat(int n)
{
	int i = 0;
	while (true) {
		if (n % 2 == 1)
			cout << i << " ";
		i++;
		n /= 2;
		if (n == 0)
			break;
	}
}
