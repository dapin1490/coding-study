/*
https://www.acmicpc.net/problem/11718
---
입력 그대로 출력하기
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string line;

	while (getline(cin, line)) {
		cout << line << '\n';
	}

	return 0;
}
