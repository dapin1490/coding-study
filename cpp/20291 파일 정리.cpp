#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> m;
map<string, int>::iterator iter;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	string s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;

		s = s.substr(s.find('.') + 1, string::npos);

		if (m.find(s) == m.end())
			m.insert(pair<string, int>(s, 1));
		else
			m[s] += 1;
	}

	for (iter = m.begin(); iter != m.end(); iter++)
		cout << (*iter).first << " " << (*iter).second << "\n";

	return 0;
}
