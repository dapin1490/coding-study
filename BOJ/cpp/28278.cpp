/*
https://www.acmicpc.net/problem/28278
---
스택 만들기. 주어지는 입력대로 동작하라.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<int> que;
    int n;
    int command;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> command;
        switch (command) {
            case 1:
                int temp;
                cin >> temp;
                que.push_back(temp);
                break;
            case 2:
                if (!que.empty()) {
                    cout << que.end()[-1];
                    que.pop_back();
                }
                else
                    cout << -1;
                cout << "\n";
                break;
            case 3:
                cout << que.size() << "\n";
                break;
            case 4:
                cout << que.empty() << "\n";
                break;
            case 5:
                if (!que.empty()) {
                    cout << que.end()[-1];
                }
                else
                    cout << -1;
                cout << "\n";
                break;
        }
    }

    return 0;
}