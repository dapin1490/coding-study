/*
https://www.acmicpc.net/problem/24313
---
주어진 n의 범위 내에서 an + b가 cn보다 작거나 같은지 확인. a, b, c와 n의 범위가 입력으로 주어진다.
*/

#include <iostream>
using namespace std;

void boj24313() {
    int a1, a0, c, n0;

    cin >> a1 >> a0 >> c >> n0;

    if (a1 > c)
        cout << 0;
    else
        cout << (a1 * n0 + a0 <= c * n0);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj24313();

    return 0;
}