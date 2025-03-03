#include <iostream>
#include <string>
using namespace std;

int time(string s);

int main() {
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	int maxi = 0;
	for (int i = 0; i < t; i++) {
		string n;
		cin >> n;
		int k = time(n);
		if (k > maxi)
			maxi = k;
	}

	cout << maxi;

	return 0;
}

int time(string s)
{
	int cnt = 0;
	while (true) {
		int i = s.find("for");
		
		if (i == -1)
			break;

		s.replace(i, 3, "#");
		cnt++;
	}
	while (true) {
		int i = s.find("while");

		if (i == -1)
			break;

		s.replace(i, 5, "#");
		cnt++;
	}

	return cnt;
}
