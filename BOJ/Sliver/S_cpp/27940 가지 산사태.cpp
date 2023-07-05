#include <iostream>
#include <vector>
using namespace std;

// https://www.acmicpc.net/problem/27940

void rain() {
    /*
    * 농장은 배열
    * 비가 올 때마다 배열 값 수정
    * 정보를 최대한 적게 저장하고 적게 변경할 방법이 있나?
    * 무너지는 층은 아무거나 출력해도 된다면 1층만 감시해도 되지 않을까?
    */
    int n, m, k; // 층 수, 비 수, 임계값
    int t, r; // 비 맞는 층 수, 강수량
    int farm = 0;

    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        cin >> t >> r;
        farm += r;
        if (farm > k) {
            cout << i << " " << 1 << "\n";
            return;
        }
    }

    cout << -1 << "\n";
    return;
}

int main()
{
    // 빠른 입출력
    ios::sync_with_stdio(false); cin.tie(NULL); std::cout.tie(NULL);

    rain();

    return 0;
}