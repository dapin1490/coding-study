/*
https://www.acmicpc.net/problem/1764
---
2개의 명단이 연속하여 주어진다. 두 명단에 모두 포함된 요소를 사전순으로 출력하라.
*/

#include <iostream>
#include <map>
using namespace std;

void boj1764();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj1764();

    return 0;
}

void boj1764() {
    map<string, pair<bool, bool>> people;
    int n, m;
    string temp;
    string answer = "";
    int cnt = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        people[temp].first = true;
    }
    for (int i = 0; i < n; i++) {
        cin >> temp;
        people[temp].second = true;
    }

    for (map<string, pair<bool, bool>>::iterator i = people.begin(); i != people.end(); i++) {
        if (i->second.first && i->second.second) {
            cnt++;
            answer += (i->first + "\n");
        }
    }

    cout << cnt << "\n" << answer;

    return;
}