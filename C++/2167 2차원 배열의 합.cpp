#include <iostream>
#include <vector>
using namespace std;

// 사각형 합
int rectsum(int li[]);

vector<vector<int>> v;
int n, m;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	v.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	int t;
	cin >> t;
	int ar[4] = { 0 };
	for (int i = 0; i < t; i++) {
		cin >> ar[0] >> ar[1] >> ar[2] >> ar[3];
		ar[0]--; ar[1]--; ar[2]--; ar[3]--;
		cout << rectsum(ar) << "\n";
	}

	return 0;
}

// 사각형 합
int rectsum(int li[])
{
	int ans = 0;
	for (int i = li[0]; i <= li[2]; i++) {
		for (int j = li[1]; j <= li[3]; j++) {
			ans += v[i][j];
		}
	}

	return ans;
}
