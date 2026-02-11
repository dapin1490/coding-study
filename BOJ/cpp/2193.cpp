#include <iostream>
using namespace std;

void boj2193();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj2193();

    return 0;
}

void boj2193() {
    int n;
    long long a = 1;
    long long b = 1;
    long long c;

    cin >> n;

    for (int i = 3; i <= n; i++) {
        switch (i % 3) {
            case 0: c = a + b; break;
            case 1: a = b + c; break;
            case 2: b = a + c; break;
        }
    }

    switch (n % 3) {
        case 0: cout << c; break;
        case 1: cout << a; break;
        case 2: cout << b; break;
    }

    return;
}