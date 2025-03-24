/*
https://www.acmicpc.net/problem/10811
---
1차원 배열을 여러 번 뒤집었을 때 마지막에 남을 결과를 출력하라
*/

#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& list, int i, int j) {
    vector<int> temp(j - i + 1);

    for (int k = i; k <= j; k++) {
        temp[temp.size() - 1 - (k - i)] = list[k];
    }
    for (int k = i; k <= j; k++) {
        list[k] = temp[k - i];
    }
}

void boj10811() {
    int n, m, i, j;
    vector<int> list;

    cin >> n >> m;

    list.resize(n + 1);
    for (int k = 1; k <= n; k++) {
        list[k] = k;
    }

    for (int k = 0; k < m; k++) {
        cin >> i >> j;
        swap(list, i, j);
    }

    for (i = 1; i < list.size(); i++) {
        cout << list[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj10811();

    return 0;
}