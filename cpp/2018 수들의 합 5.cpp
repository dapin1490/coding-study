#include <iostream>
using namespace std;

int main()
{
    int n, p1, p2, cnt, ns;
    
    cin >> n;
    
    cnt = 1; // n 포함
    p1 = 1;
    while (p1 <= n) {
        p2 = p1 + 1;
        ns = p1 + p2;
        while (p2 <= n) {
            if (ns < n)
                ns += ++p2;
            else if (ns >= n) {
                cnt += (ns == n) ? 1 : 0;
                break;
            }
        }
        p1++;
    }
    
    cout << cnt;
    
    return 0;
}
