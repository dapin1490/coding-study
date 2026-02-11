#include <iostream>
#include <string>
using namespace std;

// 덧셈
void plus_p();
// 뺄셈, 답이 양수
void minus_p();

string a, b;

int main() {
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;

	if (a.length() <= 10 && b.length() <= 10) {
		long long na = stoi(a);
		long long nb = stoi(b);
		cout << na + nb << "\n";
		return 0;
	}

	if (a.at(0) != '-' && b.at(0) != '-') { // 양양 덧셈
		plus_p();
		return 0;
	}
	else if (a.at(0) == '-' && b.at(0) == '-') { // 음음 덧셈
		a.erase(0, 1); b.erase(0, 1);
		cout << "-";
		plus_p();
		return 0;
	}
	
	if (a.at(0) == '-') { // a만 음수
		if ((a.length() - 1 == b.length() && a.substr(1, a.length() - 1) <= b) || 
			a.length() - 1 < b.length()) { // 양음 덧셈, 양수
			minus_p();
		}
		else { // 양음 덧셈, 음수
			a.erase(0, 1);
			b = '-' + b;
			cout << "-";
			minus_p();
		}
	}
	else { // b만 음수
		if ((b.length() - 1 == a.length() && b.substr(1, b.length() - 1) <= a) ||
			b.length() - 1 < a.length()) { // 양음 덧셈, 양수
			minus_p();
		}
		else { // 양음 덧셈, 음수
			b.erase(0, 1);
			a = '-' + a;
			cout << "-";
			minus_p();
		}
	}

	return 0;
}

// 덧셈
void plus_p()
{
	string ans;
	int up = 0;
	int na = a.length(), nb = b.length();

	if (na > nb) {
		int m = na - nb;
		b.insert(0, m, '0');
	}
	else if (na < nb) {
		int m = nb - na;
		a.insert(0, m, '0');
	}

	for (int i = a.length() - 1; i >= 0; i--) {
		na = int(a.at(i) - '0');
		nb = int(b.at(i) - '0');
		ans = char((na + nb + up) % 10 + '0') + ans;
		up = (na + nb + up) / 10;
	}

	if (up > 0) {
		ans = char(up + '0') + ans;
	}

	cout << ans;
}

// 뺄셈, 답이 양수
void minus_p()
{
	string ans;
	int dn = 0, up = 0;
	int na = a.length(), nb = b.length();

	if (a.at(0) == '-') { // 무조건 a - b로 계산하게 함
		string temp = a;
		a = b;
		b = temp;
	}

	b.erase(0, 1);
	na = a.length(); nb = b.length();
	if (na > nb) {
		int m = na - nb;
		b.insert(0, m, '0');
	}
	else if (na < nb) {
		int m = nb - na;
		a.insert(0, m, '0');
	}

	for (int i = a.length() - 1; i >= 0; i--) {
		na = int(a.at(i) - '0');
		nb = int(b.at(i) - '0');
		int num = na - nb + dn;
		if (num < 0) {
			dn = -1;
			up = 10;
			ans = char((num + up) % 10 + '0') + ans;
		}
		else {
			dn = 0;
			ans = char(num + '0') + ans;
		}
	}

	while (!ans.empty()) {
		if (ans.at(0) == '0')
			ans.erase(0, 1);
		else
			break;
	}

	if (ans.empty()) {
		cout << 0;
	}
	else {
		cout << ans;
	}
}
