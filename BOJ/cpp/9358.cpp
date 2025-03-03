#include <iostream>
using namespace std;

string fold_game();
void fold(int* n, long long* sq);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 1; i <= t; i++)
		cout << "Case #" << i << ": " << fold_game() << "\n";

	return 0;
}

string fold_game()
{
	int n;
	long long* sq;

	cin >> n;
	sq = new long long[n];

	for (int i = 0; i < n; i++)
		cin >> *(sq + i);

	while (n >= 2) {
		if (n == 2)
			return ((*(sq + 0) > *(sq + 1)) ? "Alice" : "Bob");
		else
			fold(&n, sq);
	}

	delete[] sq;
}

void fold(int* n, long long* sq)
{
	int len = (*n + 1) / 2;

	for (int i = 0; i < len; i++)
		*(sq + i) += *(sq + *n - 1 - i);

	*n = len;

	return;
}