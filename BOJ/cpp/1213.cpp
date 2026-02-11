#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 5번
    /*
    * 대문자만 줄 거고, 어차피 순서를 바꿀 거니까 원본 문자열은 형체가 안 남아도 됨.
    * 카운팅 후 홀수 개인 문자가 하나 이하로 있는지 확인
    * 괜찮으면 진행, 아니면 불가
    */

    vector<int> cnt(26, 0);
    vector<string> alpha = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    string name;
    string ans = "";
    int i, j, odd = 0, idx = -1;

    cin >> name;

    // count
    for (char c : name) {
        cnt[c - 'A']++;
    }

    // odd check
    for (i = 0; i < 26; i++) {
        if (cnt[i] % 2 != 0) {
            odd++;
            idx = i;
            cnt[i]--;
        }
    }

    // return fail
    if (odd > 1) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    // pre-palindrome
    for (i = 0; i < 26; i++) {
        for (j = 0; j < cnt[i] / 2; j++) {
            ans += alpha[i];
        }
    }

    // mid-palindrome
    if (idx != -1) {
        ans += alpha[idx];
    }

    // post-palindrome
    for (i = 25; i >= 0; i--) {
        for (j = 0; j < cnt[i] / 2; j++) {
            ans += alpha[i];
        }
    }

    cout << ans;

    return 0;
}