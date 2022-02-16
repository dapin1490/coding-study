#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	long long ans = 0;
	cin >> a >> b;

	for (int i = 0; i < a.length(); i++) {
		for (int j = 0; j < b.length(); j++) {
			int na = static_cast<int>(a.at(i) - '0');
			int nb = int(b.at(j) - '0');
			ans += na * nb;
		}
	}

	cout << ans;

	return 0;
}
