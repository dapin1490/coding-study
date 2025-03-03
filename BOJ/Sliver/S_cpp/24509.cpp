#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(pair<int, int> u, pair<int, int> t) {
	if (u.first == t.first)
		return u.second > t.second;
	return u.first < t.first;
}

vector<pair<int, int>> v1;
vector<pair<int, int>> v2;
vector<pair<int, int>> v3;
vector<pair<int, int>> v4;

int main() {
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	v1.resize(t); v2.resize(t); v3.resize(t); v4.resize(t);

	for (int i = 0; i < t; i++) {
		int ar[5] = { 0 };
		cin >> ar[0] >> ar[1] >> ar[2] >> ar[3] >> ar[4];
		v1[i].first = ar[1]; v2[i].first = ar[2]; v3[i].first = ar[3]; v4[i].first = ar[4];
		v1[i].second = ar[0]; v2[i].second = ar[0]; v3[i].second = ar[0]; v4[i].second = ar[0];
	}

	sort(v1.begin(), v1.end(), cmp); sort(v2.begin(), v2.end(), cmp); sort(v3.begin(), v3.end(), cmp); sort(v4.begin(), v4.end(), cmp);

	int ans[4] = { 100, 100, 100, 100 };
	vector<bool> prized(t + 1, false);

	ans[0] = v1[t - 1].second; prized[ans[0]] = true;

	for (int i = t - 1; i >= 0; i--) {
		if (!prized[v2[i].second]) {
			ans[1] = v2[i].second;
			prized[ans[1]] = true;
			break;
		}
	}

	for (int i = t - 1; i >= 0; i--) {
		if (!prized[v3[i].second]) {
			ans[2] = v3[i].second;
			prized[ans[2]] = true;
			break;
		}
	}

	for (int i = t - 1; i >= 0; i--) {
		if (!prized[v4[i].second]) {
			ans[3] = v4[i].second;
			prized[ans[3]] = true;
			break;
		}
	}

	cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3];

	return 0;
}
