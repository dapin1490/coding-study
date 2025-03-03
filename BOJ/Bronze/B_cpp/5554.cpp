#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, total;

	total = 0;
	for (int i = 0; i < 4; i++) {
		cin >> n;
		total += n;
	}

	cout << total / 60 << "\n" << total % 60;

	return 0;
}
