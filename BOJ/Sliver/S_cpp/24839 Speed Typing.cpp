#include <iostream>
#include <string>
using namespace std;

int check(string key, string value);

int main()
{
    // 빠른 입출력
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t;
    string key, value;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cin >> key >> value;
        int ans = check(key, value);
        cout << "Case #" << i << ": ";
        if (ans < 0)
            cout << "IMPOSSIBLE";
        else
            cout << ans;
        cout << "\n";
    }

    return 0;
}

int check(string key, string value)
{
    int notword = 0;
    int inword = key.length();
    int okword = 0;

    if (value.length() < key.length())
        return -1;

    while (true) {
        if (key.length() <= 0 || value.length() <= 0)
            break;

        if (key.at(0) != value.at(0)) {
            value.erase(0, 1);
            notword++;
        }
        else {
            key.erase(0, 1);
            value.erase(0, 1);
            okword++;
        }
    }

    if (inword == okword)
        return notword + value.length();
    else
        return -1;
}
