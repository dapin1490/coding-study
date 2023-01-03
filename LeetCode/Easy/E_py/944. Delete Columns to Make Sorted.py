class Solution(object):
    def minDeletionSize(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        answer = 0
        row = len(strs)
        col = len(strs[0])

        for i in range(0, col):
            for j in range(1, row):
                if strs[j - 1][i] > strs[j][i]:
                    answer += 1
                    break

        return answer