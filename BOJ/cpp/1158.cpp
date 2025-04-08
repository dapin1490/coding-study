/*
https://www.acmicpc.net/problem/1158
---
원형 순열에서 K번에 하나씩 요소를 제거한다. 모든 요소가 제거될 때까지 제거되는 순서를 출력하라.
---
boj1158_2()가 더 오래걸림
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void boj1158() {
    int n, k, idx = 0;
    vector<int> list;
    vector<int> answer;

    cin >> n >> k;
    k--;

    list.resize(n);
    for (int i = 0; i < n; i++) {
        list[i] = i + 1;
    }

    while (answer.size() < n) {
        idx = (idx + k) % list.size();
        answer.push_back(list[idx]);
        list.erase(list.begin() + idx);
    }

    cout << "<";
    for (int i = 0; i < n - 1; i++) {
        cout << answer[i] << ", ";
    }
    cout << answer[answer.size() - 1] << ">";

    return;
}

void boj1158_2() {
    int n, k;
    queue<int> list;
    vector<int> answer;

    cin >> n >> k;
    k--;

    for (int i = 1; i <= n; i++) {
        list.push(i);
    }

    while (!list.empty()) {
        for (int i = 0; i < k; i++) {
            int temp = list.front();
            list.pop();
            list.push(temp);
        }
        answer.push_back(list.front());
        list.pop();
    }

    cout << "<";
    for (int i = 0; i < n - 1; i++) {
        cout << answer[i] << ", ";
    }
    cout << answer[answer.size() - 1] << ">";

    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj1158();

    return 0;
}