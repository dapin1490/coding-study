/*
https://www.acmicpc.net/problem/19532
---
이차방정식의 모든 계수와 상수항이 주어진다. 유일한 해를 구하라.
*/

#include <iostream>
using namespace std;

void boj19532() {
    float a, b, c, d, e, f;

    cin >> a >> b >> c >> d >> e >> f;

    cout << int((c * e - b * f) / (a * e - b * d)) << " " << int((c * d - a * f) / (b * d - a * e));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj19532();

    return 0;
}