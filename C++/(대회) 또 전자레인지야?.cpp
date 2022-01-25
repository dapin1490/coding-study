#include <iostream>
#include <string>
using namespace std;

int ten = 10;
int onemi = 60;
int tenmi = 600;
int startb = 30; // 조리 시작 버튼

int start(int sec);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	int ms = static_cast<int>(s.at(0) - '0') * 600 + static_cast<int>(s.at(1) - '0') * 60
		+ static_cast<int>(s.at(3) - '0') * 10 + static_cast<int>(s.at(4) - '0');

	cout << start(ms);
	
	return 0;
}

int start(int sec)
{
	int cnt = 0;

	if (sec < 30)
	{
		cnt += sec / ten;
		return cnt + 1; // 조리 시작 버튼 + 1
	}
	else if (sec == 30) // 바로 조리 시작
		return 1;
	else if (sec % 60 >= 30)
	{
		cnt++;
		sec -= 30; // 조리 시작 버튼 먼저 누름
		cnt += sec / tenmi; // 10분 버튼
		sec %= tenmi;
		cnt += sec / onemi; // 1분 버튼
		sec %= onemi;
		cnt += sec / startb; // 조리 시작 버튼(조리 시작 + 중간에 누르면 30초 추가)
		sec %= startb;
		cnt += sec / ten; // 10초 버튼

		return cnt;
	}

	// 위의 경우가 모두 아니라면
	cnt += sec / tenmi; // 10분 버튼
	sec %= tenmi;
	cnt += sec / onemi; // 1분 버튼
	sec %= onemi;
	cnt = cnt + (sec / startb) + 1; // 조리 시작 버튼(조리 시작 + 중간에 누르면 30초 추가)
	sec %= startb;
	cnt += sec / ten; // 10초 버튼

	return cnt;
}
