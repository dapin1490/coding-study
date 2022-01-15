#include <iostream>
using namespace std;

int main()
{
    int n; // 입력받은 십진법 수
    cin >> n;

    int ans = 0; // 답

    while (true)
    {
        if (n == 0)
            break;
        ans = (ans + n % 2) * 2;
        
        n = n / 2;
    }

    cout << ans / 2;


    return 0;
}
