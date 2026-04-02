#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n;
    cin >> n;
    n = pow(pow(2, n) + 1, 2);
    cout << n;

    return 0;
}