/*
https://www.acmicpc.net/problem/2594
---
놀이공원의 놀이기구 운영 시간을 알려주겠다. 해당 시간 전후로 10분간, 그리고 해당 시간 동안은 놀면 안 된다.
주어진 시간표에서 가장 오래 쉴 수 있는 시간을 분 단위로 출력하라.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<bool> timetable(60 * 12 + 1, true);
    int n;
    int before, after;
    int max_rest = 0, temp_rest = 0;
    bool cnt = false;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> before >> after;

        before = (before / 100 - 10) * 60 + before % 100 - 10;
        if (before < 0)
            before = 0;
        after = (after / 100 - 10) * 60 + after % 100 + 10;
        if (after > 12 * 60)
            after = 12 * 60;

        for (int j = before; j < after; j++) {
            if (timetable[j])
                timetable[j] = false;
        }
    }

    for (int i = 0; i < 60 * 12; i++) {
        if (!cnt && timetable[i]) {
            temp_rest++;
            cnt = true;
        }
        else if (cnt && timetable[i]) {
            temp_rest++;
        }
        else if (cnt && !timetable[i]) {
            cnt = false;
            max_rest = (temp_rest > max_rest ? temp_rest : max_rest);
            temp_rest = 0;
        }
    }
    max_rest = (temp_rest > max_rest ? temp_rest : max_rest);

    cout << max_rest;
}