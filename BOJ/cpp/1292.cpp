#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;
	a--; b--; // 인덱스는 0부터 세니까 1씩 뺀다

	vector<long long> v(1, 1);

	int i = 2;
	while (true) {
		if (v.size() > b)
			break;

		long long cnt = v.back();
		for (int j = 0; j < i; j++) {
			cnt += i;
			v.push_back(cnt);
		}
		i++;
	}

	if (a > 0)
		cout << v[b] - v[a - 1];
	else
		cout << v[b];

	return 0;
}
