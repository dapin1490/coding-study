#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;
	int cnt = 0, idx = 0;

	for (int i = 0; i < s.length(); i++) {
		if (isupper(s.at(i))) {
			if (idx % 4 != 0) {
				int k = 4 - (idx % 4);
				idx += k;
				cnt += k;
			}
			idx++;
			continue;
		}
		idx++;
	}

	cout << cnt;

	return 0;
}
