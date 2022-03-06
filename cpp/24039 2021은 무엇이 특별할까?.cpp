#include <iostream>
#include <vector>
using namespace std;

vector<int> v(1001);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	v.at(0) = 1; // 소수가 아니니까 1로 초기화
	v.at(1) = 1;

	for (int i = 2; i <= 1000; i++)
		for (int j = 2 * i; j <= 1000; j += i)
			v.at(j) = 1;

	int n;
	cin >> n;
	int a = 0, ans = 0;
	int b = 0;

	while (true) {
		if (ans > n)
			break;

		while (v[a] != 0) { a++; }
		while (v[b] != 0 || b <= a) { b++; }
		ans = a * b;
		a++;
	}

	cout << ans;

	return 0;
}
