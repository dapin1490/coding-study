#include<iostream>
using namespace std;

int main() {
    int total, n, price, cnt, sum_total;
    sum_total = 0;
    
    cin >> total >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> price >> cnt;
        sum_total += price * cnt;
    }
    
    cout << ((total == sum_total) ? "Yes" : "No");
    
    return 0;
}
