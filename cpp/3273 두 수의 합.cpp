#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, x, cnt;
	int* ar;

	cin >> n;
	ar = new int[n];

	for (int i = 0; i < n; i++)
		cin >> *(ar + i);

	cin >> x;

	sort(ar, ar + n);
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (*(ar + i) + *(ar + j) == x)
				cnt++;
			if (*(ar + i) + *(ar + j) > x)
				break;
		}
	}

	cout << cnt;

	delete [] ar;

	return 0;
}
