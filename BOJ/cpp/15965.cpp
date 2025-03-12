/*
https://www.acmicpc.net/problem/15965
---
K번째 소수를 출력하라. K는 최대 50만이다.
*/

#include <iostream>
#include <vector>
using namespace std;

void boj15965() {
	vector<bool> primes(7368787 + 1, true);
	int k;
	int cnt = 0;

	primes[0] = false;
	primes[1] = false;

	for (int i = 2; i < primes.size(); i++) {
		if (primes[i]) {
			int j = i + i;
			while (j < primes.size()) {
				primes[j] = false;
				j += i;
			}
		}
	}

	cin >> k;

	for (int i = 2; i < primes.size(); i++) {
		if (primes[i])
			cnt++;
		if (cnt == k) {
			cout << i;
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	boj15965();

	return 0;
}