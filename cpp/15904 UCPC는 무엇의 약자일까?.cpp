#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;
	getline(cin, s);
	char ar[] = { 'U', 'C', 'P', 'C' };
	bool ok = true;

	for (int i = 0; i < 4; i++) {
		int idx = s.find(ar[i]);
		
		if (idx == -1) {
			ok = false;
			break;
		}

		s.erase(0, idx + 1);
	}

	if (ok)
		cout << "I love UCPC";
	else
		cout << "I hate UCPC";

	return 0;
}
