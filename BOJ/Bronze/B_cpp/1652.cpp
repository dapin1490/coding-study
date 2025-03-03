#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> v;
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int seatcnt = 0;
	int cnt1 = 0, cnt2 = 0;
	// 가로로 눕기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char a = v[i].at(j);
			if (a == '.')
				seatcnt++;

			if (a == 'X' || j >= n - 1) {
				if (seatcnt >= 2)
					cnt1++;
				seatcnt = 0;
			}
		}
	}

	// 세로로 눕기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char a = v[j].at(i);
			if (a == '.')
				seatcnt++;

			if (a == 'X' || j >= n - 1) {
				if (seatcnt >= 2)
					cnt2++;
				seatcnt = 0;
			}
		}
	}

	cout << cnt1 << " " << cnt2;

	return 0;
}
