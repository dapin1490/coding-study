#include <iostream>
using namespace std;

int euclidean(int big, int small);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a1, a2, b1, b2;
	int ans1, ans2, div;

	cin >> a1 >> a2 >> b1 >> b2;

	ans1 = a1 * b2 + b1 * a2;
	ans2 = a2 * b2;
	div = euclidean(ans1, ans2);

	cout << ans1 / div << " " << ans2 / div;

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
