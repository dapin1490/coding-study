#include <algorithm>
#include <vector>
using namespace std;

// https://leetcode.com/problems/contains-duplicate/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        bool flag = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i])
                flag = true;
        }
        return flag;
    }
};