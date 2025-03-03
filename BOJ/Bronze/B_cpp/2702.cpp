#include <iostream>
using namespace std;

int euclidean(int big, int small);

int main() {
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;

		int n = euclidean(a, b);
		cout << a * b / n << " " << n << "\n";
	}

	return 0;
}

int euclidean(int big, int small)
{
	if (big < small) { // 대소관계 정리
		int temp = big;
		big = small;
		small = temp;
	}

	int last = 1; // 매 연산마다 나머지를 저장함

	while (true)
	{
		if (big % small == 0)
			break;
		last = big % small;
		big = small;
		small = last;
	}

	return small;
}
