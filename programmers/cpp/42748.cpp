/*
https://school.programmers.co.kr/learn/courses/30/lessons/42748
---
배열의 일부분을 정렬한 후 그 결과 내에서 특정 위치의 값을 반환하는 연산을 주어진 명령어의 개수만큼 수행해 결과를 반환하라
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        vector<int> temp(commands[i][1] - commands[i][0] + 1);
        copy(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1], temp.begin());
        sort(temp.begin(), temp.end());
        answer.push_back(temp[commands[i][2] - 1]);
    }

    return answer;
}