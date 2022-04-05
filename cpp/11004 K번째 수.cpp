#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k;
	int* ar;

	cin >> n >> k;

	ar = new int[n];

	for (int i = 0; i < n; i++)
		cin >> *(ar + i);

	sort(ar, ar + n);

	cout << *(ar + k - 1);

	delete[] ar;

	return 0;
}
