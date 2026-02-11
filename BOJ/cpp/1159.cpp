#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void boj1159();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj1159();

    return 0;
}

void boj1159() {
    vector<int> alpha;
    int n;
    string text;

    alpha.resize(26);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> text;
        alpha[text[0] - 'a']++;
    }
    text = "";

    for (int i = 0; i < 26; i++) {
        if (alpha[i] >= 5)
            text += (i + 'a');
    }

    if (text.size() > 0)
        cout << text;
    else
        cout << "PREDAJA";

    return;
}