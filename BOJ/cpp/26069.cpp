/*
https://www.acmicpc.net/problem/26069
---
사람들이 만난 기록이 N개 주어진다. 이 기록 중 ChongChong과 만난 사람들은 무지개 댄스를 추기 시작하고, 무지개 댄스는 전염성이 있다. 만남이 끝났을 때 몇 명이나 무지개 댄스를 추고 있을지 출력하라. 대소문자를 구분한다.
*/

#include <iostream>
#include <map>
using namespace std;

void boj26069() {
    int n;
    map<string, bool> dance;
    string human1, human2;
    bool h1flag, h2flag;
    int cnt = 0;

    dance["ChongChong"] = true;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> human1 >> human2;

        h1flag = dance.find(human1) != dance.end();
        h2flag = dance.find(human2) != dance.end();

        if (h1flag && h2flag) {
            dance[human1] = (dance[human1] || dance[human2]);
            dance[human2] = (dance[human1] || dance[human2]);
        }
        else if (h1flag) {
            dance[human2] = dance[human1];
        }
        else if (h2flag) {
            dance[human1] = dance[human2];
        }
        else {
            dance[human1] = false;
            dance[human2] = false;
        }
    }

    for (auto i = dance.begin(); i != dance.end(); i++) {
        if (i->second) {
            cnt++;
        }
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj26069();

    return 0;
}