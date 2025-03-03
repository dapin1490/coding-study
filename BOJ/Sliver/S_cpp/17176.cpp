#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<int> v;
	int n;
	int idx;
	string s;
	bool ok;

	cin >> n;

	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	getline(cin, s);
	if (s.empty())
		getline(cin, s);

	ok = true;
	for (int i = 0; i < n; i++) {
		if (v[i] == 0)
			idx = s.find(" ");
		else if (v[i] >= 1 && v[i] <= 26)
			idx = s.find(char(v[i] + 'A' - 1));
		else
			idx = s.find(char(v[i] + 'a' - 27));

		if (idx == -1) {
			ok = false;
			break;
		}
		else
			s.erase(idx, 1);
	}

	if (ok)
		cout << "y";
	else
		cout << "n";

	return 0;
}
