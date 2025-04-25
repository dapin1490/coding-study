/*
https://www.acmicpc.net/problem/23056
---
체육대회 참가자 명단을 만들어라. 선착순 인원 제한이 있으며, 조건에 맞게 정렬해서 출력해야 한다.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct student {
    unsigned long long len;
    string name;
};

struct cmp {
    bool operator()(student a, student b) {
        if (a.len > b.len)
            return true;
        else if (a.len == b.len)
            return a.name > b.name;
        else
            return false;
    }
};

void boj23056();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj23056();

    return 0;
}

void boj23056() {
    vector<priority_queue<student, vector<student>, cmp>> teams;
    int n, m;
    int cls;
    string name;

    cin >> n >> m;
    teams.resize(n + 1, priority_queue<student, vector<student>, cmp>());

    while (true) {
        cin >> cls >> name;

        if (cls == 0 && name == "0")
            break;

        if (teams[cls].size() < m)
            teams[cls].push(student{ name.length(), name });
    }

    for (int i = 1; i <= n; i += 2) {
        while (!teams[i].empty()) {
            cout << i << " " << teams[i].top().name << "\n";
            teams[i].pop();
        }
    }
    for (int i = 0; i <= n; i += 2) {
        while (!teams[i].empty()) {
            cout << i << " " << teams[i].top().name << "\n";
            teams[i].pop();
        }
    }

    return;
}
