#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ar[5] = { 0 };

	for (int i = 0; i < 5; i++) {
		cin >> ar[i];
	}

	sort(ar, ar+5);

	int ans = ar[2];
	int cnt = 0;
	while (true) {
		for (int i = 0; i < 5; i++) {
			if (ans % ar[i] == 0)
				cnt++;
		}

		if (cnt >= 3)
			break;

		cnt = 0;
		ans++;
	}

	cout << ans;

	return 0;
}