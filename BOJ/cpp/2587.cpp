/*
https://www.acmicpc.net/problem/2587
---
평균과 중앙값을 출력하라

퀵 선택 알고리즘 사용
*/

#include <iostream>
#include <vector>
#include <random>
using namespace std;

int quickselect(vector<int> A, int k);
int findmedian(vector<int> lis);
void boj2587();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj2587();

    return 0;
}

int quickselect(vector<int> lis, int k) {
    int pivot;
    uniform_int_distribution<int> dis(0, lis.size() - 1);
    mt19937 gen(1490);
    vector<vector<int>> comp(3, vector<int>());

    if (lis.size() == 1)
        return lis[0];

    pivot = lis[dis(gen)];

    for (int i = 0; i < lis.size(); i++) {
        if (lis[i] < pivot)
            comp[0].push_back(lis[i]);
        else if (lis[i] > pivot)
            comp[2].push_back(lis[i]);
        else
            comp[1].push_back(lis[i]);
    }

    if (k < comp[0].size())
        return quickselect(comp[0], k);
    else if (k < comp[0].size() + comp[1].size())
        return pivot;
    else
        return quickselect(comp[2], k - comp[0].size() - comp[1].size());
}

int findmedian(vector<int> lis) {
    int n = lis.size();

    if (n % 2 == 1)
        return quickselect(lis, (n - 1) / 2);
    else {
        int m1 = quickselect(lis, n / 2 - 1);
        int m2 = quickselect(lis, n / 2);
        return (m1 + m2) / 2;
    }
}

void boj2587() {
    vector<int> lis(5);
    int total = 0;

    for (int i = 0; i < 5; i++) {
        cin >> lis[i];
        total += lis[i];
    }

    cout << total / 5 << "\n" << findmedian(lis);

    return;
}
