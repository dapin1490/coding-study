#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 빠른 입출력
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k, cnt;
    vector<int> v;

    cin >> n >> k;
    v.resize(n + 1, 0);
    v.at(0) = 1; // 소수가 아니니까 1로 초기화
    v.at(1) = 1;

    cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (v.at(i) == 1)
            continue;
        else {
            cnt++;
            v.at(i) = 1;
            if (cnt == k) {
                cout << i;
                return 0;
            }
        }
        for (int j = 2 * i; j <= n; j += i) {
            if (v.at(j) == 0) {
                cnt++;
                v.at(j) = 1;
                if (cnt == k) {
                    cout << j;
                    return 0;
                }
            }
        }
    }

    return 0;
}
