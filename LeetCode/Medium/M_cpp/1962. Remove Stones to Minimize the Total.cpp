#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// https://leetcode.com/problems/remove-stones-to-minimize-the-total/
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> que(piles.begin(), piles.end()); // 주어진 배열의 값들로 이루어진 우선순위 큐(내림차순) 생성
        int total = 0; // 총합

        for (int i = 0; i < k; i++) { // 돌무더기 덜어내기 연산
            int num = que.top(); // top은 항상 최댓값이다
            que.pop(); // top이 자동으로 pop을 수행하지 않기 때문에 따로 해줘야 함.
            que.push(num - num / 2); // 아까 그 top에 돌무더기 덜어내기 연산을 수행한 후 다시 큐에 넣는다
        }

        while(!que.empty()) { // 총합 구하기 : 모든 연산을 큐에 있는 값으로 했기 때문에 더할 때도 큐에 있는 값을 써야 한다
            total += que.top();
            que.pop();
        }

        return total;
    }
};