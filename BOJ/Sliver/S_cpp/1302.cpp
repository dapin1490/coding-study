#include <iostream>
#include <map>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	map<string, int> mp;
	map<string, int>::iterator iter;
	int n, bestsellcnt;
	string name, bestseller;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> name;

		if (mp.find(name) != mp.end())
			mp[name]++;
		else
			mp.insert(pair<string, int>(name, 1));
	}

	bestsellcnt = 0;
	for (iter = mp.begin(); iter != mp.end(); iter++) {
		if ((*iter).second > bestsellcnt) {
			bestsellcnt = (*iter).second;
			bestseller = (*iter).first;
		}
	}

	cout << bestseller;

	return 0;
}
