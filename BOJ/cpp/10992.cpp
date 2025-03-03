/*
https://www.acmicpc.net/problem/10992
---
속이 빈 삼각형 모양으로 별을 찍어라
*/

#include <iostream>
using namespace std;

void print_space(int n) {
	for (int i = 0; i < n; i++) {
		cout << " ";
	}
}

void print_star(int n) {
	for (int i = 0; i < n; i++) {
		cout << "*";
	}
}

void boj10992() {
	int n;

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		/*
		0 <= i < n - 1 -> n - i - 1개 만큼 공백 출력 후 * 1개 출력 후 마지막에 * 출력
		i == n - 1 -> 전부 * 출력
		*/
		print_space(n - i - 1);
		print_star(1);
		if (n - i < n) {
			print_space(2 * i - 1);
			print_star(1);
		}
		cout << "\n";
	}
	print_star(2 * n - 1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	boj10992();

	return 0;
}
