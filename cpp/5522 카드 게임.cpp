#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long n, total;

	total = 0;
	for (int i = 0; i < 5; i++) {
		cin >> n;
		total += n;
	}

	cout << total;

	return 0;
}
