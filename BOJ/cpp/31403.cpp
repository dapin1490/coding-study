/*
https://www.acmicpc.net/problem/31403
---
세 정수가 주어진다. 이들을 숫자로 취급할 경우 +, -는 일반적인 사칙연산의 규칙을 따르지만, 이들을 문자열로 취급할 경우 +는 문자열의 연결을, -는 그 문자열을 숫자로 취급하여 뺄셈하는 것을 의미한다. 주어진 세 정수를 각각 숫자로 취급한 경우와 문자열로 취급한 경우의 $A + B - C$의 결과를 출력하라.
*/

#include <iostream>
#include <string>
using namespace std;

void boj31403() {
	int a, b, c;
	int res1, res2;

	cin >> a >> b >> c;

	res1 = a + b - c;
	res2 = stoi(to_string(a) + to_string(b)) - c;

	cout << res1 << "\n" << res2;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	boj31403();

	return 0;
}