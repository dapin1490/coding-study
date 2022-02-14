#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 쿼리 함수
long long q1(int a, int b);
long long q2(int a, int b, int c, int d);

// 수열 저장
vector<int> v;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int m, a, b, c, d;
	for (int i = 0; i < q; i++) {
		cin >> m;
		switch (m)
		{
		case 1:
			cin >> a >> b;
			cout << q1(a, b) << "\n";
			break;
		case 2:
			cin >> a >> b >> c >> d;
			cout << q2(a, b, c, d) << "\n";
			break;
		}
	}

	return 0;
}

// 쿼리 함수
long long q1(int a, int b)
{
	a--; b--;
	long long ans = 0;
	for (int i = a; i <= b; i++)
		ans += v[i];

	swap(v[a], v[b]);
	return ans;
}

long long q2(int a, int b, int c, int d)
{
	a--; b--; c--; d--;
	long long ans = 0;

	if (b >= c && b < d && a <= c) {
		for (int i = a; i < c; i++)
			ans += v[i];
		for (int j = b + 1; j <= d; j++)
			ans -= v[j];
	}
	else {
		for (int i = a; i <= b; i++)
			ans += v[i];
		for (int j = c; j <= d; j++)
			ans -= v[j];
	}
	return ans;
}
