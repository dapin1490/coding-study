/*
https://www.acmicpc.net/problem/2948
---
2009년 날짜가 주어지면 그 날이 무슨 요일인지 출력. 2009년 1월 1일은 목요일이다. 요일은 영어로 출력한다.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<vector<int>> calender(12);
	vector<int> month = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	vector<string> day = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	int day_input, month_input;
	int idx = 3;

	for (int i = 0; i < 12; i++)
		calender[i].resize(month[i]);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < month[i]; j++) {
			calender[i][j] = idx;
			idx = (idx + 1) % 7;
		}
	}

	cin >> day_input >> month_input;

	cout << day[calender[month_input - 1][day_input - 1]];

	return 0;
}