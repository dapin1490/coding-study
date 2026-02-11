#include <iostream>
using namespace std;

/*
기차 승하차 시뮬레이션
*/

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int cnt = 0;
    int minus, plus;
    int max_cnt = 0;

    for (int i = 0; i < 4; i++) {
        cin >> minus >> plus;
        max_cnt = (cnt > max_cnt ? cnt : max_cnt);
        cnt -= minus;
        max_cnt = (cnt > max_cnt ? cnt : max_cnt);
        cnt += plus;
        max_cnt = (cnt > max_cnt ? cnt : max_cnt);
    }

    cout << max_cnt;

    return 0;
}