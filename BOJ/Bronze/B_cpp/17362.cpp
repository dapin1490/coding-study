#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	n %= 8;

	switch (n) {
	case 1:
		cout << 1;
		break;
	case 2: case 0:
		cout << 2;
		break;
	case 3: case 7:
		cout << 3;
		break;
	case 4: case 6:
		cout << 4;
		break;
	case 5:
		cout << 5;
	}

	return 0;
}
