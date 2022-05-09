#include <iostream>
using namespace std;

int main()
{
    long long int t[36] = { 0 };
    int n;
    t[0] = 1;
    
    for (int i = 1; i <= 35; i++)
        for (int j = 0; j < i; j++)
            t[i] += t[j] * t[i - j - 1];
    
    cin >> n;
    
    cout << t[n];
    
    return 0;
}
