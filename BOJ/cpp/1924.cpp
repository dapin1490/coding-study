#include <iostream>
using namespace std;

void boj1924();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj1924();

    return 0;
}

void boj1924() {
    int mon = 1, day = 1, x, y, totalday = 0;
    string daycode[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
    int daysize[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    cin >> x >> y;

    while (mon != x || day != y) {
        if (x > mon) {
            totalday += daysize[mon];
            mon++;
        }
        else {
            totalday += (y - day);
            day += (y - day);
        }
    }

    cout << daycode[totalday % 7];

    return;
}

/*
* (1) 매일 시뮬레이션
* (2) 일주일 단위로 스킵하기
* (3) 날짜 수만 계산해서 7로 나누기
*/