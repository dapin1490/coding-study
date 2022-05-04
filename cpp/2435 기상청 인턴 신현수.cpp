#include <iostream>
using namespace std;

int main()
{
    int n, k, maxi, sumi;
    int* p;
    
    cin >> n >> k;
    
    p = new int [n];
    sumi = 0;
    for (int i = 0; i < n; i++) {
        cin >> *(p + i);
        sumi += (i < k) ? *(p + i) : 0;
    }
    maxi = sumi;
    
    for (int i = k; i < n; i++) {
        sumi = sumi - *(p + i - k) + *(p + i);
        maxi = (sumi > maxi) ? sumi : maxi;
    }
    
    cout << maxi;
    
    delete[] p;
    
    return 0;
}
