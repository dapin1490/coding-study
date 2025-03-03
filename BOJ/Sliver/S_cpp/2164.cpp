#include <iostream>
#include <queue>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	queue<int> que;
	int n;
	bool discard = true;

	cin >> n;
	for (int i = 1; i <= n; i++)
		que.push(i);

	while (que.size() > 1) {
		if (discard) {
			que.pop();
		}
		else {
			int card = que.front();
			que.pop();
			que.push(card);
		}
		discard = !discard;
	}

	cout << que.front();

	return 0;
}
