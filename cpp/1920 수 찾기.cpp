#include <iostream>
#include <algorithm>
using namespace std;

bool bisearch(int* a, int n, int key);

int main()
{
    // 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m, key;
    int* ar;
    
    cin >> n;
    
    ar = new int[n];
    for (int i = 0; i < n; i++)
        cin >> *(ar + i);
    sort(ar, ar + n);
    
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> key;
        cout << (bisearch(ar, n, key) ? 1 : 0) << "\n";
    }
    
    delete[] ar;
    
    return 0;
}

bool bisearch(int* a, int n, int key)
{
    int li = 0;
    int hi = n - 1;
    while (li <= hi) {
        int mid = (li + hi) / 2;
        
        if (*(a + mid) == key)
            return true;
        else if (*(a + mid) > key)
            hi = mid - 1;
        else
            li = mid + 1;
    }
    return false;
}
