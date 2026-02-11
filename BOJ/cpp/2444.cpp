#include <iostream>
#include <string>
using namespace std;

void boj2444();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj2444();

    return 0;
}

void boj2444() {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << string(n - i, ' ') << string(2 * i - 1, '*') << "\n";
    }
    for (int i = n - 1; i > 0; i--) {
        cout << string(n - i, ' ') << string(2 * i - 1, '*') << "\n";
    }

    return;
}