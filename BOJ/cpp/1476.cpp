#include <iostream>
#include <vector>
using namespace std;

/*
 * https://www.acmicpc.net/problem/1476
 * 문제집에서 찾아서 푸는 문제라 브루트포스라는 건 알고 있음
 * 범위를 정해놓고 숫자를 늘리면서 카운트만 하면 되는거지
 */

int year_count(vector<int>& dday) { // 15, 28, 19
	vector<int> today = vector<int>(3, 1);
	int cnt = 1;

	while (dday != today) {
		today[0] = (++today[0] > 15 ? 1 : today[0]);
		today[1] = (++today[1] > 28 ? 1 : today[1]);
		today[2] = (++today[2] > 19 ? 1 : today[2]);

		cnt++;
	}

	return cnt;
}

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<int> dday = vector<int>(3, 1); // 15, 28, 19

	cin >> dday[0] >> dday[1] >> dday[2];
	cout << year_count(dday);

    return 0;
}