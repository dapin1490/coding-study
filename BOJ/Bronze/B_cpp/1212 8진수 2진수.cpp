#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string ar[] = { "000", "001", "010", "011", "100", "101", "110", "111" };

	string n;
	cin >> n;

	string ans = "" + to_string(stoi(ar[int(n.at(0) - '0')]));
	for (int i = 1; i < n.length(); i++) {
		ans += ar[int(n.at(i) - '0')];
	}

	cout << ans;

	return 0;
}
