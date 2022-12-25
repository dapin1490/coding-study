#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	int** ar; // 이중 포인터

	cin >> n >> m;

	// 포인터 이차원 배열
	ar = new int* [n]; // 1차 참조에서 포인터 배열 할당
	for (int i = 0; i < n; i++)
		*(ar + i) = new int[n]{ 0 }; // 2차 참조에서 정수 배열 할당과 초기화

	// 파스칼의 삼각형 테두리
	for (int i = 0; i < n; i++) {
		*(*(ar + i) + 0) = 1;
		*(*(ar + i) + i) = 1;
	}
	
	// 파스칼의 삼각형 안쪽
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i; j++)
			*(*(ar + i) + j) = *(*(ar + i - 1) + j - 1) + *(*(ar + i - 1) + j);
	}

	// 출력
	cout << *(*(ar + n - 1) + m - 1);

	// 메모리 해제
	for (int i = 0; i < n; i++)
		delete[] * (ar + i);
	delete[]ar;

	return 0;
}
