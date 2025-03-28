/*
https://school.programmers.co.kr/learn/courses/30/lessons/12939
---
공백으로 구분된 숫자 배열이 문자열로 주어진다. 최댓값과 최솟값을 찾아 마찬가지로 문자열로 반환하라.
*/

#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    size_t idx = s.find(" ");
    vector<int> nums;
    string temp;
    int mi, ma;

    while (idx != string::npos) {
        temp = s.substr(0, idx);
        nums.push_back(stoi(temp));
        s = s.substr(idx + 1);
        idx = s.find(" ");
    }
    if (!s.empty()) {
        nums.push_back(stoi(s));
    }

    mi = nums[0]; // find min
    ma = nums[0]; // find max
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < mi)
            mi = nums[i];
        if (nums[i] > ma)
            ma = nums[i];
    }

    return to_string(mi) + " " + to_string(ma);
}

/*
#include <iostream>

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string in;

    getline(cin, in);
    cout << solution(in);

    return 0;
}
*/