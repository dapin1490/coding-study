#include <iostream>
#include <vector>
#include <map>
using namespace std;

void boj10986();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj10986();

    return 0;
}

void boj10986() {
    int n, m;
    long long cnt = 0;
    vector<int> list;
    map<int, long long> mods;

    cin >> n >> m;
    list.resize(n);

    cin >> list[0];
    list[0] %= m;
    mods[list[0]] = 1;
    for (int i = 1; i < n; i++) {
        cin >> list[i];
        list[i] = (list[i] % m + list[i - 1]) % m;
        if (mods.find(list[i]) != mods.end())
            mods[list[i]]++;
        else
            mods[list[i]] = 1;
    }

    for (auto iter = mods.begin(); iter != mods.end(); iter++) {
        cnt += (iter->second * (iter->second - 1) / 2);
    }

    cout << cnt + mods[0];

    return;
}
