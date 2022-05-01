#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, cnt;
	char digit;
	string sn;

	cin >> n >> digit;

	cnt = 0;
	for (int i = 1; i <= n; i++) {
		sn = to_string(i);
		if (sn.find(digit) != string::npos) {
			for (int j = 0; j < sn.length(); j++)
				cnt += (sn.at(j) == digit) ? 1 : 0;
		}
	}

	cout << cnt;

	return 0;
}
