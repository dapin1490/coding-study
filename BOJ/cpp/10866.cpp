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

	m.insert(pair<string, int>("push_front", 0));
	m.insert(pair<string, int>("push_back", 1));
	m.insert(pair<string, int>("pop_front", 2));
	m.insert(pair<string, int>("pop_back", 3));
	m.insert(pair<string, int>("size", 4));
	m.insert(pair<string, int>("empty", 5));
	m.insert(pair<string, int>("front", 6));
	m.insert(pair<string, int>("back", 7));

	int t, num;
	string query;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> query;

		switch (m[query]) {
		case 0:
			// push_front X: 정수 X를 덱의 앞에 넣는다.
			cin >> num;
			v.insert(v.begin(), num);
			break;
		case 1:
			// push_back X: 정수 X를 덱의 뒤에 넣는다.
			cin >> num;
			v.insert(v.end(), num);
			break;
		case 2:
			// pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다.
			// 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
			if (v.empty())
				cout << -1;
			else {
				cout << v.front();
				v.erase(v.begin());
			}
			cout << "\n";
			break;
		case 3:
			// pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다.
			// 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
			if (v.empty())
				cout << -1;
			else {
				cout << v.back();
				v.erase(v.end() - 1);
			}
			cout << "\n";
			break;
		case 4:
			// size: 덱에 들어있는 정수의 개수를 출력한다.
			cout << v.size() << "\n";
			break;
		case 5:
			// empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
			cout << (v.empty() ? 1 : 0) << "\n";
			break;
		case 6:
			// front: 덱의 가장 앞에 있는 정수를 출력한다.
			// 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
			cout << (v.empty() ? -1 : v.front()) << "\n";
			break;
		case 7:
			// back: 덱의 가장 뒤에 있는 정수를 출력한다.
			// 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
			cout << (v.empty() ? -1 : v.back()) << "\n";
			break;
		}
	}

	return 0;
}
