#include <iostream>
#include <vector>
using namespace std;

void boj2460();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj2460();

    return 0;
}

void boj2460() {
    int cnt = 0, maxi = 0;
    int add, minus;

    for (int i = 0; i < 10; i++) {
        cin >> minus >> add;
        cnt = cnt - minus + add;
        if (cnt > maxi)
            maxi = cnt;
    }

    cout << maxi;

    return;
}