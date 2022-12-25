#include <iostream>
#include <set>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	set<int> s;
	set<int>::iterator iter;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		s.insert(a);
	}

	for (iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << " ";

	return 0;
}
