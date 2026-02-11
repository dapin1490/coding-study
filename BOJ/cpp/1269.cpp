/*
https://www.acmicpc.net/problem/1269
---
두 개의 정수 집합이 주어진다. 두 집합 각각에서 한 쪽에만 속한 원소의 개수를 구하라.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b);

void boj1269();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj1269();

    return 0;
}

bool cmp(int a, int b) {
    if (a <= b)
        return true;
    else
        return false;
}

void boj1269() {
    int n1, n2;
    vector<int> s1;
    vector<int> s2;
    int idx1 = 0, idx2 = 0;
    int cnt = 0;

    cin >> n1 >> n2;
    s1.resize(n1);
    s2.resize(n2);

    for (int i = 0; i < n1; i++)
        cin >> s1[i];
    for (int i = 0; i < n2; i++)
        cin >> s2[i];

    sort(s1.begin(), s1.end(), cmp);
    sort(s2.begin(), s2.end(), cmp);

    while (idx1 < n1 && idx2 < n2) {
        if (s1[idx1] == s2[idx2]) {
            idx1++;
            idx2++;
        }
        else if (s1[idx1] > s2[idx2]) {
            cnt++;
            idx2++;
        }
        else if (s1[idx1] < s2[idx2]) {
            cnt++;
            idx1++;
        }
    }

    if (idx1 < n1)
        cnt += (n1 - idx1);
    else if (idx2 < n2)
        cnt += (n2 - idx2);

    cout << cnt;
    return;
}