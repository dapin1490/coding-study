#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, maxi;
	int* p;
	int* subp;

	cin >> n;
	p = new int[n];
	subp = new int[n];

	for (int i = 0; i < n; i++)
		cin >> *(p + i);
	*(subp + 0) = *(p + 0);
	maxi = *(subp + 0);

	for (int i = 1; i < n; i++) {
		*(subp + i) = (*(p + i) + *(subp + i - 1) > *(p + i)) ? *(p + i) + *(subp + i - 1) : *(p + i);
		if (*(subp + i) > maxi)
			maxi = *(subp + i);
	}

	cout << maxi;

	delete[] p;
	delete[] subp;

	return 0;
}
