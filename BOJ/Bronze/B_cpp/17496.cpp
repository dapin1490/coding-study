#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, t, c, p;
	cin >> n >> t >> c >> p;

	cout << ((n - 1) / t) * c * p;

	return 0;
}
