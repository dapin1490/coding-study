#include <iostream>
using namespace std;

void boj2738();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj2738();

    return 0;
}

void boj2738() {
    int maxi = 0;
    int temp;
    int x = 1, y = 1;

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> temp;
            if (temp > maxi) {
                x = i;
                y = j;
                maxi = temp;
            }
        }
    }

    cout << maxi << "\n" << x << " " << y;

    return;
}