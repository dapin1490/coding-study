/*
https://www.acmicpc.net/problem/1009
---
10대의 컴퓨터에 차례대로 a^b개의 일을 시키려고 한다. 마지막에 일하는 컴퓨터는 몇 번인가? 주어진 t개의 테스트 케이스에 대해 각각 답하라.
*/

#include <iostream>
using namespace std;

int boj1009() {
	int a, b;
	int res = 1;

	cin >> a >> b;

	for (int i = 0; i < b; i++) {
		res = (res * a) % 10;
	}

	if (res == 0)
		res = 10;

	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cout << boj1009() << '\n';
	}

	return 0;
}