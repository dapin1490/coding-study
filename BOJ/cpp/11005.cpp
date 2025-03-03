#include <iostream>
#include <string>
using namespace std;

// 진법 변환
string change(long long n, int b);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long n, b;
	cin >> n >> b;

	cout << change(n, b);

	return 0;
}

// 진법 변환
string change(long long n, int b)
{
	string ans = "";

	while (true) {
		if (n == 0)
			break;

		int last = n % b;

		if (last < 10) {
			ans.insert(0, to_string(last));
		}
		else {
			char alpha = 'A' + last - 10;
			ans.insert(0, 1, alpha);
		}

		n /= b;
	}

	return ans;
}
