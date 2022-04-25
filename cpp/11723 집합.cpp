#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	bool s[21] = { 0 };
	bool allT[21] = { 0 };
	bool allF[21] = { 0 };
	string inst;
	int m, x;

	for (int i = 0; i <= 20; i++)
		allT[i] = 1;

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> inst;

		if (inst == "all") { copy(allT, allT + 21, s); continue; }
		else if (inst == "empty") { copy(allF, allF + 21, s); continue; }

		cin >> x;

		switch (inst.at(0))
		{
		case 'a': s[x] = 1; break; // add
		case 'r': s[x] = 0; break; // remove
		case 'c': cout << (s[x] ? 1 : 0) << "\n"; break; // check
		case 't': s[x] = (s[x] ? 0 : 1); break; // toggle
		}
	}

	return 0;
}
