#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	map<string, int> mp;
	string* idx;
	int n, m;
	string name;

	cin >> n >> m;

	idx = new string[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> name;
		mp.insert(pair<string, int>(name, i));
		*(idx + i) = name;
	}

	for (int i = 0; i < m; i++) {
		cin >> name;
		if (name.at(0) >= '0' && name.at(0) <= '9')
			cout << *(idx + stoi(name)) << "\n";
		else
			cout << mp[name] << "\n";
	}

	delete[] idx;

	return 0;
}
