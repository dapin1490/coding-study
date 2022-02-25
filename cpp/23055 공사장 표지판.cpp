#include <iostream>
using namespace std;

int main() {
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) { // 몇 번째 줄 출력하는지
		for (int j = 0; j < n; j++) { // i번째 줄에서 몇 번째 자리 출력하는지
			if (j == 0 || j == n - 1 || j == i || j == n - 1 - i || i == 0 || i == n - 1) {
				cout << "*";
			}
			else
				cout << " ";
		}
		cout << "\n";
	}

	return 0;
}
