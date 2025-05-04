/*
https://www.acmicpc.net/problem/25305
---
n명 중 k명만 상을 받을 수 있다. 커트라인을 구하라.

퀵 선택 사용
*/

#include <iostream>
#include <vector>
#include <random>
using namespace std;

int quickselect(vector<int> A, int k);
void boj25305();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj25305();

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

void boj25305() {
    int n, k;
    vector<int> lis;

    cin >> n >> k;
    lis.resize(n);

    for (int i = 0; i < n; i++)
        cin >> lis[i];

    cout << quickselect(lis, n - k);

    return;
}
