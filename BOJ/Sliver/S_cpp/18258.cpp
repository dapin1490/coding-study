#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;

queue<int> q;
map<string, int> m;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	m.insert(pair<string, int>("push", 0));
	m.insert(pair<string, int>("pop", 1));
	m.insert(pair<string, int>("size", 2));
	m.insert(pair<string, int>("empty", 3));
	m.insert(pair<string, int>("front", 4));
	m.insert(pair<string, int>("back", 5));

	int t, num;
	string query;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> query;

		switch (m[query]) {
		case 0:
			cin >> num;
			q.push(num);
			break;
		case 1:
			if (q.empty()) {
				cout << -1;
			}
			else {
				cout << q.front();
				q.pop();
			}
			cout << "\n";
			break;
		case 2:
			cout << q.size() << "\n";
			break;
		case 3:
			if (q.empty())
				cout << 1;
			else
				cout << 0;
			cout << "\n";
			break;
		case 4:
			if (q.empty()) {
				cout << -1;
			}
			else {
				cout << q.front();
			}
			cout << "\n";
			break;
		case 5:
			if (q.empty()) {
				cout << -1;
			}
			else {
				cout << q.back();
			}
			cout << "\n";
			break;
		}
	}

	return 0;
}
