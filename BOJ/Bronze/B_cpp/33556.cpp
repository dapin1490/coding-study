/*
https://www.acmicpc.net/contest/problem/33556
---
다음 조건에 따라 두 가지 함수를 정의한다. 두 단어 `A`, `B`가 입력으로 주어질 때 각 함수의 결과값을 출력하라.
- `A.equals(B)`
    - 대소문자를 구분해 두 단어의 문자열이 동일한지 판별한다.
    - A가 `"null"` 일 경우 `null` 타입이 주어진 것으로 간주해 `NullPointerException` 을 반환하지만 B가 `"null"` 인 경우는 오류를 반환하지 않는다.
- `A.equalsIgnoreCase(B)`
    - 대소문자에 무관하게 두 단어의 문자열이 동일한지 판별한다.
    - A가 `"null"` 일 경우 `null` 타입이 주어진 것으로 간주해 `NullPointerException` 을 반환하지만 B가 `"null"` 인 경우는 오류를 반환하지 않는다.
*/

#include <iostream>
#include <string>
using namespace std;

string lower(string a) {
	string res = "";

	for (char i : a) {
		res += tolower(i);
	}

	return res;
}

bool is_null(string a) {
	string key = "null";

	if (a.size() == key.size()) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != key[i])
				return false;
		}
		return true;
	}
	else
		return false;
}

string equals(string a, string b) {
	if (is_null(a))
		return "NullPointerException";

	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i])
				return "false";
		}
		return "true";
	}
	else
		return "false";
}

string equalsIgnoreCase(string a, string b) {
	if (is_null(a))
		return "NullPointerException";

	if (!is_null(a) && is_null(b))
		return "false";

	a = lower(a);
	b = lower(b);

	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i])
				return "false";
		}
		return "true";
	}
	else
		return "false";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string a, b;

	cin >> a >> b;

	cout << equals(a, b) << "\n";
	cout << equalsIgnoreCase(a, b) << "\n";

	return 0;
}