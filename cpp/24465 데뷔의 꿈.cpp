#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int star(int m, int d);

bool zodiac[12] = { 0 };
vector<pair<int, int>> v;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int mon, day, n;
	bool flag;

	// 기존 멤버 별자리 표시
	for (int i = 0; i < 7; i++) {
		cin >> mon >> day;

		zodiac[star(mon, day)] = 1;
	}

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> mon >> day;

		v.push_back(make_pair(mon, day));
	}

	sort(v.begin(), v.end());

	flag = true;
	for (int i = 0; i < n; i++) {
		int idx = star(v[i].first, v[i].second);

		if (!zodiac[idx]) {
			cout << v[i].first << " " << v[i].second << "\n";
			flag = false;
		}
	}

	if (flag)
		cout << "ALL FAILED";

	return 0;
}

int star(int m, int d)
{
	/*
	0. 물병자리		1월 20일 ~ 2월 18일
	1. 물고기자리	2월 19일 ~ 3월 20일
	2. 양자리		3월 21일 ~ 4월 19일
	3. 황소자리		4월 20일 ~ 5월 20일
	4. 쌍둥이자리	5월 21일 ~ 6월 21일
	5. 게자리		6월 22일 ~ 7월 22일
	6. 사자자리		7월 23일 ~ 8월 22일
	7. 처녀자리		8월 23일 ~ 9월 22일
	8. 천칭자리		9월 23일 ~ 10월 22일
	9. 전갈자리		10월 23일 ~ 11월 22일
	10. 사수자리		11월 23일 ~ 12월 21일
	11. 염소자리		12월 22일 ~ 1월 19일
	*/
	
	switch (m) {
	case 1:
		if (d <= 19) return 11;
		else return 0;
	case 2:
		if (d <= 18) return 0;
		else return 1;
	case 3:
		if (d <= 20) return 1;
		else return 2;
	case 4:
		if (d <= 19) return 2;
		else return 3;
	case 5:
		if (d <= 20) return 3;
		else return 4;
	case 6:
		if (d <= 21) return 4;
		else return 5;
	case 7:
		if (d <= 22) return 5;
		else return 6;
	case 8:
		if (d <= 22) return 6;
		else return 7;
	case 9:
		if (d <= 22) return 7;
		else return 8;
	case 10:
		if (d <= 22) return 8;
		else return 9;
	case 11:
		if (d <= 22) return 9;
		else return 10;
	case 12:
		if (d <= 21) return 10;
		else return 11;
	}
}
