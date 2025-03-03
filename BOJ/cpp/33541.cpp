/*
https://www.acmicpc.net/problem/33541
---
주어진 네 자리 숫자보다 큰 숫자 중에서 다음 조건을 만족하는 가장 작은 수를 찾아라. 없으면 -1.
- 네 자리 숫자에 대해, 숫자의 앞 두 자리와 뒤 두 자리를 더한 뒤 제곱한 값이 원래 숫자와 같은 것
*/

#include <iostream>
#include <string>
using namespace std;

int boj33541(int n) {
	int res = 0;

	while (res != n && n < 9999) {
		n++;
		res = (n / 100) + (n % 100);
		res = res * res;
	}

	if (n >= 9999)
		return -1;
	else
		return n;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;

	cin >> n;

	cout << boj33541(n);

	return 0;
}