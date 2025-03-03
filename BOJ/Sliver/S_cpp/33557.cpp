/*
https://www.acmicpc.net/problem/33557
---
A x B를 세로식 곱셈에서 받아올림을 하지 않고 바로 결과에 적는 잘못된 곱셈 결과가 일반 곱셈 결과와 같은지 판별하라. 만약 두 수의 자릿수가 달라 잘못된 곱셈에서 자릿수가 짧은 수의 자리가 비어 있는 경우, 자릿수가 긴 수의 숫자만을 결과에 기록한다.

테스트케이스마다 결과를 출력하라
*/

#include <iostream>
#include <string>
using namespace std;

void two_sort(long long& a, long long& b) {
	if (a < b) {
		long long temp = a;
		a = b;
		b = temp;
	}
}

int boj33557() {
	long long a;
	long long b;
	string correct;
	string wrong = "";

	cin >> a >> b;
	correct = to_string(a * b);
	two_sort(a, b);

	while (a > 0 && b > 0) {
		wrong = to_string((a % 10) * (b % 10)) + wrong;
		a /= 10;
		b /= 10;
	}
	while (a > 0) {
		wrong = to_string(a % 10) + wrong;
		a /= 10;
	}

	return (correct == wrong ? 1 : 0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cout << boj33557() << "\n";
	}

	return 0;
}