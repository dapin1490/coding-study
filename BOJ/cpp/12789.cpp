/*
https://www.acmicpc.net/problem/12789
---
반드시 순서대로 처리해야 하는 일이 있는데, 대기열이 뒤섞여 있다. 옆에는 추가 대기열 하나뿐이고, 통로가 좁아 나중에 들어간 사람이 먼저 나올 수밖에 없다. 이 상황에서 대기열 순서가 주어질 때, 모든 대기자가 처리될 수 있는지 판별하라.
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void boj12789();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj12789();

    return 0;
}

void boj12789() {
    queue<int> que;
    stack<int> stk;
    int n, temp1, temp2;
    int idx = 1;
    bool is_ok = true;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp1;
        que.push(temp1);
    }

    while (idx <= n) {
        if (!que.empty()) temp1 = que.front();
        else temp1 = n + 1;
        if (!stk.empty()) temp2 = stk.top();
        else temp2 = n + 1;

        if (temp1 < temp2) {
            que.pop();
            if (temp1 != idx) stk.push(temp1);
            else idx++;
        }
        else if (temp1 > temp2) {
            if (temp2 == idx) {
                idx++;
                stk.pop();
            }
            else {
                is_ok = false;
                break;
            }
        }
    }

    cout << (is_ok ? "Nice" : "Sad");
    return;
}