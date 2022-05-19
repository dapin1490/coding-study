#include <iostream>
using namespace std;

int euclidean(int big, int small);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	int* p;

	cin >> n;
	p = new int[n];
	
	for (int i = 0; i < n; i++)
		cin >> *(p + i);

	for (int i = 1; i < n; i++) {
		int div = euclidean(*(p + 0), *(p + i));
		cout << *(p + 0) / div << "/" << *(p + i) / div << "\n";
	}

	delete[] p;

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
