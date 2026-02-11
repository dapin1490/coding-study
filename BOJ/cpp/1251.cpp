#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string reverse_word(string word);
void boj1251();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj1251();

    return 0;
}

string reverse_word(string word) {
    string answer = "";

    for (int i = word.length() - 1; i >= 0; i--)
        answer += word[i];

    return answer;
}

void boj1251() {
    string word, part1, part2, part3;
    int i, j; // 0번부터 i글자, i번부터 j - i글자, j + 1번부터 끝까지
    vector<string> dict;

    cin >> word;

    for (i = 1; i <= word.length() - 2; i++) {
        part1 = reverse_word(word.substr(0, i));
        for (j = i + 1; j <= word.length() - 1; j++) {
            part2 = reverse_word(word.substr(i, j - i));
            part3 = reverse_word(word.substr(j));
            dict.push_back(part1 + part2 + part3);
        }
    }

    sort(dict.begin(), dict.end());

    cout << dict[0];

    return;
}

/*
* 단어 길이가 짧고, 이렇다 할 법칙을 찾기 어려우니 브루트포스가 필요하다 판단
* 2개의 인덱스로 자를 위치 정하기
    * 외부 for문, 내부 for문 모두 순서대로 돌기
    * 내부 for문은 항상 외부 for문보다 1 큰 값으로 시작
* 잘라낸 단어 뒤집기
* 붙인 단어들은 따로 저장해서 사전순 정렬
*/