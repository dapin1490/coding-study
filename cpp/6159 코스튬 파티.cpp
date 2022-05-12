#include <iostream>
using namespace std;

int main()
{
    // 빠른 입출력
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, s;
    int* cow;
    int cnt;
    
    cin >> n >> s;
    
    cow = new int[n];
    for (int i = 0; i < n; i++)
        cin >> *(cow + i);
    
    cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(cow + i) + *(cow + j) <= s)
                cnt++;
        }
    }
    
    cout << cnt;
    
    delete[] cow;
    
    return 0;
}
