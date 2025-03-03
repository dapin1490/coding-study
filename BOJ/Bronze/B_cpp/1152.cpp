#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int cnt = 0;
	while (true) {
		if (cin.eof() == true)
			break;

		string word;
		cin >> word;
		cnt++;
	}

	cout << cnt - 1;

	return 0;
}
