#include <iostream>
#include <algorithm>
using namespace std;

bool bisearch(int* c, int hi, int n);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	int* card;
	int num;

	cin >> n;

	card = new int[n];
	for (int i = 0; i < n; i++)
		cin >> *(card + i);

	sort(card, card + n);

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> num;
		cout << (bisearch(card, n, num) ? 1 : 0) << " ";
	}

	return 0;
}

bool bisearch(int* c, int hi, int n)
{
	int li = 0;

	while (li <= hi) {
		int mid = (li + hi) / 2;
		if (n == *(c + mid))
			return true;
		else if (n > *(c + mid))
			li = mid + 1;
		else
			hi = mid - 1;
	}
	
	return false;
}
