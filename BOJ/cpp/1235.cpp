#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void boj1235();
void reverse(string::iterator first, string::iterator last);

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj1235();

    return 0;
}

void boj1235() {
    vector<string> nums;
    int n, answer;
    bool ok = false;

    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        reverse(nums[i].begin(), nums[i].end());
    }

    sort(nums.begin(), nums.end());

    answer = to_string(n).size() - 1;
    while (!ok) {
        ok = true;
        answer++;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1].substr(0, answer) == nums[i].substr(0, answer)) {
                ok = false;
                break;
            }
        }
    }

    cout << answer;

    return;
}

// reference: https://blockdmask.tistory.com/363
void reverse(string::iterator first, string::iterator last) {
    char temp;

    while ((first != last) && first != --last) {
        temp = *first;
        *first = *last;
        *last = temp;
        first++;
    }

    return;
}