#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	string s;
	int num = 1;
	while (s.length() < k && num - 1 < n) {
		if (s.length() > 1000 && k > 1000) {
			s.erase(0, 1000);
			k -= 1000;
		}

		s += to_string(num);
		num++;
	}

	if (s.length() >= k && num - 1 <= n)
		cout << s.at(k - 1);
	else
		cout << -1;

	return 0;
}
