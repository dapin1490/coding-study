#include <iostream>
#include <vector>
using namespace std;

// 증가하는 수열 찾기
int finder(int n);

vector<int> v;
vector<int> d;
int t, cnt = 1;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a;
	cin >> t;
	d.resize(t, 1);
	for (int i = 0; i < t; i++) {
		cin >> a;
		v.push_back(a);
	}

	a = 1;
	while (true) {
		if (a >= t)
			break;

		int k = finder(a);
		if (cnt < k) {
			cnt = k;
		}
		a++;
	}

	cout << cnt;

	return 0;
}

// 증가하는 수열 찾기
int finder(int n)
{
	for (int i = n; i >= 0; i--) {
		if (v[i] < v[n] && d[i] >= d[n]) {
			d[n] = d[i] + 1;
		}
	}

	return d[n];
}
