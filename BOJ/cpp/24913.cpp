/*
https://www.acmicpc.net/problem/24913
---
개표,,를 할 건데
출제자가 현재 개표 상황에 대해 특정 조건이 부여되면 자신이 당선 가능성이 있는지 알고 싶어 한다. 개표를 진행하면서 중간중간 그의 쿼리에 답변해줘라.
---
reference: https://devmill.tistory.com/55
*/

#include <iostream>
#include <vector>
using namespace std;

void boj24913();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj24913();

    return 0;
}

void boj24913() {
    int n, q;
    int query, x, y;
    long long total = 0;
    long long maxi = 0;
    vector<long long> votes;

    cin >> n >> q;
    votes.resize(n + 2, 0);

    for (int i = 0; i < q; i++) {
        cin >> query >> x >> y;

        switch (query) {
        case 1:
            votes[y] += x;
            if (y != (n + 1)) {
                total += x;
                if (votes[y] > maxi)
                    maxi = votes[y];
            }
            break;
        case 2:
            long long mean = total + y;
            long long temp = votes[n + 1] + x;
            if (temp > maxi && (temp - 1) * n >= mean)
                cout << "YES\n";
            else
                cout << "NO\n";
            break;
        }
    }
}
