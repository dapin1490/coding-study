#include <iostream>
#include <algorithm>
using namespace std;

bool is_in_memo(int* mem, int n, int key);
void memory_test();

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		memory_test();

	return 0;
}

bool is_in_memo(int* mem, int n, int key)
{
	int li, hi, mid;

	li = 0;
	hi = n;
	while (li <= hi) {
		mid = (li + hi) / 2;

		if (key == *(mem + mid))
			return true;
		else if (key > *(mem + mid))
			li = mid + 1;
		else
			hi = mid - 1;
	}

	return false;
}

void memory_test()
{
	int n, m;
	int* memo1;
	int memo2;

	cin >> n;
	memo1 = new int[n];

	for (int i = 0; i < n; i++)
		cin >> *(memo1 + i);
	sort(memo1, memo1 + n);

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> memo2;
		cout << (is_in_memo(memo1, n, memo2) ? "1\n" : "0\n");
	}

	delete[] memo1;

	return;
}
