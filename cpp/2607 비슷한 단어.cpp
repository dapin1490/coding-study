#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t, cnt = 0;
	cin >> t;

	string key;
	cin >> key;
	int len = key.length();

	for (int i = 1; i < t; i++) {
		string value;
		cin >> value;
		int notword = 0;

		for (int j = 0; j < len; j++) {
			int idx = value.find(key.at(j));
			if (idx != -1) {
				value.erase(idx, 1);
			}
			else
				notword++;
		}

		if (notword <= 1 && value.length() <= 1) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
