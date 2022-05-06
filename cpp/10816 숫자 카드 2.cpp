#include <iostream>
#include <map>
using namespace std;

int main()
{
    // 빠른 입출력
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    map<int, int> v;
    int n, m, num;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;

        if (v.find(num) != v.end())
            v[num]++;
        else
            v.insert(pair<int, int>(num, 1));
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> num;

        if (v.find(num) != v.end())
            cout << v[num] << " ";
        else
            cout << "0 ";
    }

    return 0;
}
