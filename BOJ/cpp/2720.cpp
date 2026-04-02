#include <iostream>
using namespace std;

int coin[4] = {25, 10, 5, 1};

void get_coin(int c);

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t, c;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> c;
        get_coin(c);
    }

    return 0;
}

void get_coin(int c) {
    int coin_cnt[4] = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++) {
        coin_cnt[i] = c / coin[i];
        c %= coin[i];
    }

    cout << coin_cnt[0] << " " << coin_cnt[1] << " " << coin_cnt[2] << " " << coin_cnt[3] << "\n";
}