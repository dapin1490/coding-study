# 912. Sort an Array: https://leetcode.com/problems/sort-an-array/
# reference: https://leetcode.com/problems/sort-an-array/solutions/277127/7-line-quicksort-to-write-in-interviews-python/
import random

class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if len(nums) <= 1:
            return nums
        
        pivot = random.choice(nums)
        lt = [v for v in nums if v < pivot]
        eq = [v for v in nums if v == pivot]
        gt = [v for v in nums if v > pivot]

        return self.sortArray(lt) + eq + self.sortArray(gt)