#include <iostream>
#include <string>
using namespace std;

// 거울상
string mirror();

string s;

int main() {
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> s;
		if (s == "#")
			break;
		cout << mirror() << "\n";
	}

	return 0;
}

// 거울상
string mirror()
{
	string ans;
	bool ok = true;
	for (int i = s.length() - 1; i >= 0; i--) {
		switch (s.at(i)) {
		case 'b': ans += 'd'; break;
		case 'd': ans += 'b'; break;
		case 'p': ans += 'q'; break;
		case 'q': ans += 'p'; break;
		case 'i': case 'o': case 'v': case 'w': case 'x':
			ans += s.at(i); break;
		default: ok = false; break;
		}
	}

	if (ok)
		return ans;
	else
		return "INVALID";
}
