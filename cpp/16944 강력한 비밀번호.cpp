#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int len, cnt;
	string pw;
	const string sc = "!@#$%^&*()-+";
	bool is_val[5] = { 0 };
	
	cin >> len >> pw;
	if (len >= 6)
		is_val[0] = true;

	for (int i = 0; i < len; i++) {
		if (pw.at(i) >= '0' && pw.at(i) <= '9')
			is_val[1] = true;
		else if (isupper(pw.at(i))) // 대문자
			is_val[2] = true;
		else if (islower(pw.at(i))) // 소문자
			is_val[3] = true;
		else if (sc.find(pw.at(i)) >= 0)
			is_val[4] = true;
	}

	cnt = 0;
	for (int i = 1; i < 5; i++) {
		if (!is_val[i])
			cnt++;
	}

	if (!is_val[0] && cnt < 6 - len)
		cnt += (6 - len - cnt);

	cout << cnt;

	return 0;
}
