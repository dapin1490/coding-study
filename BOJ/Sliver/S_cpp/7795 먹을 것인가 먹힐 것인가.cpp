#include <iostream>
#include <algorithm>
using namespace std;

int count_eat(int* a, int na, int* b, int nb);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t, na, nb;
	int* a;
	int* b;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> na >> nb;

		a = new int[na];
		b = new int[nb];

		for (int j = 0; j < na; j++)
			cin >> *(a + j);
		for (int j = 0; j < nb; j++)
			cin >> *(b + j);

		sort(a, a + na);
		sort(b, b + nb);

		cout << count_eat(a, na, b, nb) << "\n";

		delete[] a;
		delete[] b;
	}

	return 0;
}

int count_eat(int* a, int na, int* b, int nb)
{
	int cnt = 0;
	int li, hi, mid;

	for (int i = 0; i < na; i++) {
		if (*(a + i) <= *(b + 0))
			continue;

		li = 0;
		hi = nb;
		mid = 0;
		while (li + 1 < hi) {
			mid = (li + hi) / 2;
			if (*(a + i) > *(b + mid))
				li = mid;
			else
				hi = mid;
		}

		cnt += (*(a + i) > *(b + li) ? li + 1 : li);
	}

	return cnt;
}
