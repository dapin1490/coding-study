#include <iostream>
using namespace std;

int main()
{
    // 빠른 입출력
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m, a, b, num;
    int* ar;
    
    num = 0;
    cin >> n >> m;
    ar = new int[n];
    
    for (int i = 0; i < n; i++) {
        cin >> *(ar + i);
        num += *(ar + i);
        *(ar + i) = num;
    }
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (a <= 1)
            cout << *(ar + b - 1) << "\n";
        else
            cout << *(ar + b - 1) - *(ar + a - 2) << "\n";
    }
    
    delete[] ar;

    return 0;
}
