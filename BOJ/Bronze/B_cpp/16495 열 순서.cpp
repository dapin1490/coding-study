#include <iostream>
#include <string>
using namespace std;

int main() {
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long ans = 0;
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		ans = (ans + int(s.at(i) - 'A') + 1) * 26;
	}

	cout << ans / 26;

	return 0;
}
