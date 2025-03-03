#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> v;
map<string, int> m;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	m.insert(pair<string, int>("push", 0));
	m.insert(pair<string, int>("pop", 1));
	m.insert(pair<string, int>("size", 2));
	m.insert(pair<string, int>("empty", 3));
	m.insert(pair<string, int>("top", 4));

	int t, num;
	string query;
	
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> query;

		switch (m[query]) {
		case 0:
			cin >> num;
			v.push_back(num);
			break;
		case 1:
			if (v.empty()) {
				cout << -1;
			}
			else {
				cout << v.back();
				v.pop_back();
			}
			cout << "\n";
			break;
		case 2:
			cout << v.size() << "\n";
			break;
		case 3:
			if (v.empty())
				cout << 1;
			else
				cout << 0;
			cout << "\n";
			break;
		case 4:
			if (v.empty()) {
				cout << -1;
			}
			else {
				cout << v.back();
			}
			cout << "\n";
			break;
		}
	}

	return 0;
}
