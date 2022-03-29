#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k, cnt;
	cin >> n >> k;

	cnt = 0;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		
		while (true) {
			if (num % 2 == 0) {
				cnt++;
				num /= 2;
			}
			else
				break;
		}
	}

	cout << (cnt >= k ? 1 : 0);

	return 0;
}
