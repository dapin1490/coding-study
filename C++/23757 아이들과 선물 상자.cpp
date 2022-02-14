#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> box;
vector<int> c;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	c.resize(m);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		box.push(a);
	}
	for (int i = 0; i < m; i++)
		cin >> c[i];

	int ans = 1;
	for (int i = 0; i < m; i++) {
		int b = box.top();
		box.pop();
		b -= c[i];
		if (b >= 0)
			box.push(b);
		else {
			ans = 0;
			break;
		}
	}

	cout << ans;

	return 0;
}
