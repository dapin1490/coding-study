#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, string> mp;
    int n, m;
    string site, pw;
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> site >> pw;
        mp.insert(pair<string, string>(site, pw));
    }
    
    for (int i = 0; i < m; i++) {
        cin >> site;
        cout << mp[site] << "\n";
    }
    
    return 0;
}
