#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v[9] = { 0 };
	int ar[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int n = 0, idx;
	for (int i = 0; i < 9; i++) {
		cin >> v[i];
		n += v[i];
	}

	sort(v, v + 9);

	for (int i = 0; i < 9; i++) {
		n -= v[i];
		ar[i] = 0;
		for (int j = i + 1; j < 9; j++) {
			n -= v[j];
			if (n == 100) {
				ar[j] = 0;
				break;
			}
			else {
				n += v[j];
			}
		}
		if (n == 100)
			break;
		n += v[i];
		ar[i] = 1;
	}

	for (int i = 0; i < 9; i++) {
		if (ar[i]) {
			cout << v[i] << "\n";
		}
	}

	return 0;
}
