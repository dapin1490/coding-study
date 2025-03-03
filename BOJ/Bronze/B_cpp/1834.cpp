#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long n;
	cin >> n;

	long long ans = 0;
	for (long long i = 1; i < n; i++) {
		ans += (n + 1) * i;
	}
	
	cout << ans;
	
	return 0;
}
