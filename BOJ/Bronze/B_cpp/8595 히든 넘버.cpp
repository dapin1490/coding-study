#include <iostream>
#include <string>
using namespace std;

int main() {
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int len; string s;
	cin >> len >> s;

	long long ans = 0;
	string strnum;
	for (int i = 0; i < len; i++) {
		char key = s.at(i);

		if (key >= '0' && key <= '9') {
			strnum += key;
		}
		else if (!strnum.empty()) {
			ans += stoi(strnum);
			strnum.clear();
		}

		if (!strnum.empty() && i == len - 1) {
			ans += stoi(strnum);
			strnum.clear();
		}
	}

	cout << ans;

	return 0;
}
