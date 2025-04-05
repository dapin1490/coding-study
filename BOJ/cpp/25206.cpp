/*
https://www.acmicpc.net/problem/25206
---
학점 계산기를 만들어라. 중복된 과목은 없다.
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<string, float> grade_crit = {
    make_pair("A+", 4.5),
    make_pair("A0", 4.0),
    make_pair("B+", 3.5),
    make_pair("B0", 3.0),
    make_pair("C+", 2.5),
    make_pair("C0", 2.0),
    make_pair("D+", 1.5),
    make_pair("D0", 1.0),
    make_pair("F", 0.0)
};

void boj25206() {
    vector<pair<float, string>> record; // time, grade
    string temp, grade_name;
    float time;
    float total_grade = 0, total_time = 0;

    while (!cin.eof()) {
        cin >> temp >> time >> grade_name;
        if (grade_name == "P")
            continue;
        record.push_back(make_pair(time, grade_name));
        grade_name = "P";
    }

    for (pair<float, string> i : record) {
        total_grade += (i.first * grade_crit[i.second]);
        total_time += i.first;
    }

    cout.precision(10);
    cout << total_grade / total_time;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj25206();

    return 0;
}