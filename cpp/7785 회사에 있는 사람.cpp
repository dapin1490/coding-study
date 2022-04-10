#include <iostream>
#include <map>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	map<string, bool> m;
	map<string, bool>::iterator iter;
	int n;
	string name, stat;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> name >> stat;

		if (m.find(name) == m.end())
			m.insert(pair<string, bool>(name, (stat == "enter" ? true : false)));
		else
			m[name] = (stat == "enter" ? true : false);
	}

	for (iter = --m.end(); iter != --m.begin(); iter--) {
		if ((*iter).second)
			cout << (*iter).first << "\n";
	}

	return 0;
}
