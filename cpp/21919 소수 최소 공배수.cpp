#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 빠른 입출력
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    long long num;
    long long ans;
    vector<int> v(1000001);
    v[0] = 1; // 소수가 아니니까 1로 초기화
    v[1] = 1;

    for (int i = 2; i <= 1000000; i++) {
        for (int j = 2 * i; j <= 1000000; j += i) {
            v[j] = 1;
        }
    }

    cin >> n;

    ans = 1;
    for (int i = 0; i < n; i++) {
        cin >> num;

        if (v[num] == 0 && ans % num != 0)
            ans *= num;
    }

    cout << (ans != 1 ? ans : -1);

    return 0;
}
