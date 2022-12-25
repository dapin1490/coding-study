#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) { return a > b; }

int main()
{
    // 빠른 입출력
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, mini, weight, max_w;
    int* rope;

    cin >> n;

    rope = new int[n];
    for (int i = 0; i < n; i++)
        cin >> *(rope + i);

    sort(rope, rope + n, cmp);

    max_w = 0;
    for (int k = 1; k <= n; k++) {
        mini = *(rope + k - 1);
        weight = mini * k;
        max_w = (weight > max_w) ? weight : max_w;
    }

    cout << max_w;

    delete[] rope;

    return 0;
}
