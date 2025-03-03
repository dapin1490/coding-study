#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	string word;
	char key;
	bool flag = true;

	cin >> n >> word;
	
	key = word.at(0);

	for (int i = 1; i < n; i++) {
		cin >> word;

		if (word.at(0) != key) {
			flag = false;
			break;
		}
	}

	cout << (flag ? 1 : 0);

	return 0;
}
