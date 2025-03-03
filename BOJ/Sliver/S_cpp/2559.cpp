#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	v.resize(n);
	long long wd = 0;
	int start = 0, end = k;
	long long maxi = 0;

	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < k; i++)
		wd += v[i];

	maxi = wd;

	for (end; end < n; end++, start++) {
		wd = wd - v[start] + v[end];
		if (wd > maxi)
			maxi = wd;
	}

	cout << maxi;

	return 0;
}
