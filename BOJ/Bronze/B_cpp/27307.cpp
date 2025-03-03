/*
https://www.acmicpc.net/problem/27037
---
4자리 숫자를 준다. 이 숫자를 이용해 다음 연산을 수행한다.

1. 원래 숫자의 두 번째, 세 번째 자리 숫자만 잘라낸다
2. 1에서 만든 숫자를 제곱한다

위의 연산을 반복해 나온 결과가 중복될 때까지 연산을 반복한다.

예를 들면 다음과 같이 `4444`로 시작할 경우 연산은 9번 이루어져야 하며, `0000`으로 마무리된다.

```
  N    2nd&3rd  Squared
4444 ... 0044 ... 1936
1936 ... 0093 ... 8649
8649 ... 0064 ... 4096
4096 ... 0009 ... 0081
0081 ... 0008 ... 0064
0064 ... 0006 ... 0036
0036 ... 0003 ... 0009
0009 ... 0000 ... 0000
0000 ... 0000 ... 0000
```

첫 줄에 4자리 숫자가 입력되면 필요한 연산의 수를 출력하라.
*/

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int middle_square(int n) {
	int num = (n / 100 % 10) * 10 + n / 10 % 10;

	return num * num;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int num1;
	unordered_set<int> dict;

	cin >> num1;

	while (dict.find(num1) == dict.end()) {
		dict.insert(num1);
		num1 = middle_square(num1);
	}

	cout << dict.size();

	return 0;
}