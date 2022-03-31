#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, total;
	int* p;
	cin >> n;

	p = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		cin >> *(p + i);
	}

	sort(p, (p + n));

	total = (n % 2 == 0) ? *(p + n / 2) : 0;
	for (int i = n - 1; i > n / 2; i--) {
		total += *(p + i);
	}

	cout << total;

	return 0;
}
