#include <iostream>
using namespace std;

int main() {
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = n; i >= 0; i--) {
		switch (i) {
		case 0:
			if (n == 1) {
				cout << "No more bottles of beer on the wall, no more bottles of beer.\n";
				cout << "Go to the store and buy some more, " << n << " bottle of beer on the wall.";
			}
			else {
				cout << "No more bottles of beer on the wall, no more bottles of beer.\n";
				cout << "Go to the store and buy some more, " << n << " bottles of beer on the wall.";
			}
			break;
		case 1:
			cout << i << " bottle of beer on the wall, " << i << " bottle of beer.\n";
			cout << "Take one down and pass it around, no more bottles of beer on the wall.\n\n";
			break;
		case 2:
			cout << i << " bottles of beer on the wall, " << i << " bottles of beer.\n";
			cout << "Take one down and pass it around, " << i - 1 << " bottle of beer on the wall.\n\n";
			break;
		default:
			cout << i << " bottles of beer on the wall, " << i << " bottles of beer.\n";
			cout << "Take one down and pass it around, " << i - 1 << " bottles of beer on the wall.\n\n";
		}
	}

	return 0;
}
