#include <iostream>
#include <string>
using namespace std;

// 덧셈
void plus_p();

string a, b;

int main() {
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;

	if (a.length() <= 10 && b.length() <= 10) {
		long long na = stoi(a);
		long long nb = stoi(b);
		cout << na + nb;
		return 0;
	}

	plus_p();

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
