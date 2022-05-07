#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string doc, word;
	int cnt, idx, len;

	getline(cin, doc);
	getline(cin, word);

	cnt = 0, idx = 0;
	len = word.length();
	while (true) {
		idx = doc.find(word);
		if (idx >= 0) {
			cnt++;
			doc.replace(idx, len, "#");
		}
		else
			break;
	}

	cout << cnt;

	return 0;
}
