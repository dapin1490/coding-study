#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/find-the-town-judge/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // 마을 주민의 번호가 1부터 시작하기 때문에 인덱스 주의
        vector<vector<bool>> trust_mat(n + 1, vector<bool>(n + 1, false)); // 신뢰 관계 행렬, 전부 false로 초기화
        vector<bool> judge_suspect(n + 1, true); // 마을 심판 용의자 배열, 전부 true로 초기화

        for (auto& i : trust) {
            trust_mat[i[0]][i[1]] = true; // 신뢰 관계 행렬 입력
            judge_suspect[i[0]] = false; // 한 명이라도 믿는 사람이 있다면 용의자 제외
        }

        for (int i = 1; i <= n; i++) { // 모든 마을 주민에 대해 반복
            if (!judge_suspect[i]) // 용의자가 아니라면 패스
                continue;
            for (int j = 1; j <= n; j++) { // 심판 용의자에 대해
                if (i == j)
                    continue;
                if (trust_mat[i][j] || !trust_mat[j][i]) {
                    // 한 명이라도 자신이 믿는 주민이 있거나, 자신을 믿지 않는 주민이 있다면 거짓
                    judge_suspect[i] = false;
                    break;
                }
            }
            if (judge_suspect[i]) // 검사 후에도 용의자가 true라면 정답
                return i;
        }

        return -1; // 모든 용의자가 심판이 아니었을 경우 마을에 심판 없음
    }
};