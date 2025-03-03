#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int answer = 0;
        int row = strs.size();
        int col = strs[0].length();

        for (int i = 0; i < col; i++) {
            for (int j = 1; j < row; j++) {
                if (int(strs[j - 1][i]) > int(strs[j][i])) {
                    cout << strs[j - 1][i] << ", " << strs[j][i] << "\n";
                    ++answer;
                    break;
                }
            }
        }

        return answer;
    }
};