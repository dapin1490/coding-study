#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, f;
	cin >> n >> f;
	int m = n - n % 100;

	while (true) {
		if (m % f == 0)
			break;
		m++;
	}

	string s = to_string(m);
	int idx = s.length();
	cout << s.at(idx - 2) << s.at(idx - 1);

	return 0;
}
