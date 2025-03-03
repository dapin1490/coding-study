#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string n;

	while (true) {
		cin >> n;
		if (n == "0")
			break;

		int len = n.length() - 1;
		bool pal = true;
		for (int i = 0; i <= len / 2; i++) {
			if (n.at(i) != n.at(len - i)) {
				pal = false;
				break;
			}
		}

		if (pal)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}
