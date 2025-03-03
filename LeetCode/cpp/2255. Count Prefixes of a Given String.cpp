#include <iostream>
#include <vector>
#include <unordered_map> // map으로 잘못 알고 있었음
using namespace std;

// https://leetcode.com/problems/count-prefixes-of-a-given-string/
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        unordered_map<int, string> dict;
        int cnt = 0; // 정답 개수

        for (int i = 1; i <= s.length(); i++)
            dict[i] = s.substr(0, i);

        for (auto& word : words) {
            if (word.length() > s.length())
                continue;
            else if (word == dict[word.length()])
                ++cnt;
        }

        return cnt;
    }
};


// 최소 런타임 샘플 답안
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int counter = 0;
        for (auto word : words) {
            if (s.find(word) == 0) {
                counter++;
            }
        }
        return counter ;
    }
};