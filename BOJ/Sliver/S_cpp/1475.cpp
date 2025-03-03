#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;
	int pan[9] = { 0 }; // 6과 9가 같은 칸에 저장됨, 숫자와 인덱스가 똑같이 사용됨
	int maxi = 0;
	int len;

	cin >> s;

	len = s.length();
	for (int i = 0; i < len; i++) {
		if (s.at(i) == '6' || s.at(i) == '9')
			pan[6]++;
		else
			pan[int(s.at(i) - '0')]++;
	}

	pan[6]++;
	pan[6] /= 2;

	for (int i = 0; i < 9; i++) {
		if (pan[i] > maxi)
			maxi = pan[i];
	}

	cout << maxi;

	return 0;
}
