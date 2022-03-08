#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int ar[26] = { 0 };
	string s;
	int maxi = 0;

	while (true) {
		cin >> s;

		if (cin.eof())
			break;

		for (int i = 0; i < s.length(); i++) {
			int idx = int(s.at(i) - 'a');
			ar[idx]++;
			if (ar[idx] > maxi)
				maxi = ar[idx];
		}
	}

	for (int i = 0; i < 26; i++) {
		if (ar[i] >= maxi)
			cout << char(i + 'a');
	}

	return 0;
}
