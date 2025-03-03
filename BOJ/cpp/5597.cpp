/*
https://www.acmicpc.net/problem/5597
---
1 이상 30 이하의 수가 중복 없이 28개 주어진다. 1부터 30까지의 수 중에 입력으로 주어지지 않은 2개의 수를 찾아 출력하라
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<int> list(31, 0);

	list[0] = 1;

	for (int i = 0; i < 28; i++) {
		int temp;
		cin >> temp;
		list[temp] = 1;
	}

	for (int i = 1; i < 31; i++) {
		if (list[i] == 0) {
			cout << i << "\n";
		}
	}

	return 0;
}