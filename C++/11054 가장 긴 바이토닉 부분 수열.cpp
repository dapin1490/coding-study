#include <iostream>
#include <vector>
using namespace std;

// 증가하는 수열 거꾸로 찾기
void downfinder(int n);
// 증가하는 수열 앞에서부터 찾기
void upfinder(int n);

vector<int> v;
vector<int> dn;
vector<int> up;
int t, cnt = 1;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a;
	cin >> t;
	dn.resize(t, 1);
	up.resize(t, 1);
	for (int i = 0; i < t; i++) {
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < t; i++) {
		upfinder(i);
		downfinder(t - 1 - i);
	}

	for (int i = 0; i < t; i++) {
		if (dn[i] + up[i] - 1 > cnt) {
			cnt = dn[i] + up[i] - 1;
		}
	}

	cout << cnt;

	return 0;
}

// 증가하는 수열 거꾸로 찾기 : t - 1부터 대입
void downfinder(int n)
{
	for (int i = n; i < t; i++) {
		if (v[i] < v[n] && dn[i] >= dn[n]) {
			dn[n] = dn[i] + 1;
		}
	}
}

// 증가하는 수열 앞에서부터 찾기 : 0부터 대입
void upfinder(int n)
{
	for (int i = n; i >= 0; i--) {
		if (v[i] < v[n] && up[i] >= up[n]) {
			up[n] = up[i] + 1;
		}
	}
}
