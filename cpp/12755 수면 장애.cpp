#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	string s;
	int num = 1;
	while (s.length() < n) {
		if (s.length() > 1000 && n > 1000) {
			s.erase(0, 1000);
			n -= 1000;
		}

		s += to_string(num);
		num++;
	}

	cout << s.at(n - 1);

	return 0;
}
