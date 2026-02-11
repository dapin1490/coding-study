#include <iostream>
#include <vector>
using namespace std;

void boj2563();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj2563();

    return 0;
}

void boj2563() {
    vector<vector<int>> field;
    int n, x, y, cnt = 0;

    field.resize(100, vector<int>(100, 0));

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        for (int a = x - 1; a < x + 9; a++) {
            for (int b = y - 1; b < y + 9; b++) {
                if (field[a][b] == 0) {
                    field[a][b] = 1;
                    cnt++;
                }
            }
        }
    }

    cout << cnt;

    return;
}