#include <iostream>
#include <string>
using namespace std;

void boj2386();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj2386();

    return 0;
}

void boj2386() {
    string line = "";
    char key, upper_key;
    int cnt = 0;

    while (true) {
        cin >> key;

        if (key == '#')
            break;

        upper_key = key - 32;
        cnt = 0;
        getline(cin, line);

        for (int i = 0; i < line.length(); i++) {
            if (line.at(i) == key || line.at(i) == upper_key)
                cnt++;
        }

        cout << key << " " << cnt << "\n";
    }

    return;
}