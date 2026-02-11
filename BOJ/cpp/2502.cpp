#include <iostream>
#include <vector>
using namespace std;

void boj2502();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj2502();

    return 0;
}

void boj2502() {
    int day, total, a1 = 1, a2;
    vector<pair<int, int>> coeff = { make_pair(1, 0), make_pair(0, 1) };

    cin >> day >> total;

    for (int i = 2; i < day; i++)
        coeff.emplace_back(coeff[i - 1].first + coeff[i - 2].first, coeff[i - 1].second + coeff[i - 2].second);

    --day;
    a2 = (total - coeff[day].first * a1) / coeff[day].second;
    while (coeff[day].first * a1 + coeff[day].second * a2 != total) {
        ++a1;
        a2 = (total - coeff[day].first * a1) / coeff[day].second;
    }

    cout << a1 << "\n" << a2;

    return;
}

/*
* 첫날과 둘째 날을 제외한 나머지는 전부 첫날과 둘째 날의 값으로 나타낼 수 있음
* 지정된 날까지 두 수의 계수만 계산해두면 됨
* 이후 1부터 브루트포스
*/