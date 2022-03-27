#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t, n, total;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;

		if (n != 0)
			s.push(n);
		else
			s.pop();
	}

	total = 0;
	while (!s.empty()) {
		total += s.top();
		s.pop();
	}

	cout << total;

	return 0;
}
