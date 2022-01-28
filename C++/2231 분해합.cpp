#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        string num = to_string(i);
        
        for (int j = 0; j < num.length(); j++)
            s += static_cast<int>(num.at(j) - '0');
        
        s += i;
        
        if (s == n)
        {
            ans = i;
            break;
        }
    }
    
    cout << ans;
    
    return 0;
}
