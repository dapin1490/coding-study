/*
https://www.acmicpc.net/problem/28279
---
덱 구현하기
*/

#include <iostream>
#include <deque>
using namespace std;

void boj28279() {
    deque<int> deck;
    int n, cmd, temp;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cmd;

        switch (cmd) {
        case 1:
            cin >> temp;
            deck.push_front(temp);
            break;
        case 2:
            cin >> temp;
            deck.push_back(temp);
            break;
        case 3:
            if (!deck.empty()) {
                temp = deck.front();
                deck.pop_front();
                cout << temp << "\n";
            }
            else
                cout << -1 << "\n";
            break;
        case 4:
            if (!deck.empty()) {
                temp = deck.back();
                deck.pop_back();
                cout << temp << "\n";
            }
            else
                cout << -1 << "\n";
            break;
        case 5:
            cout << deck.size() << "\n";
            break;
        case 6:
            cout << deck.empty() << "\n";
            break;
        case 7:
            if (!deck.empty())
                cout << deck.front() << "\n";
            else
                cout << -1 << "\n";
            break;
        case 8:
            if (!deck.empty())
                cout << deck.back() << "\n";
            else
                cout << -1 << "\n";
            break;
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj28279();

    return 0;
}