# Time:  O(n^3 * 4^n), n = 4
# Space: O(n^2)

from fractions import Fraction
from operator import *

class Solution(object):
    def judgePoint24(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        def dfs(nums):
            if len(nums) == 1:
                return nums[0] == 24
            ops = [add, sub, mul, div]
            for i in xrange(len(nums)):
                for j in xrange(len(nums)):
                    if i == j:
                        continue
                    for op in ops:
                        if op == div and nums[j] == 0:
                            continue
                        next_nums = [nums[k] for k in xrange(len(nums)) if k not in [i, j]]
                        next_nums.append(op(nums[i], nums[j]))
                        if dfs(next_nums):
                            return True
            return False

        return dfs(map(lambda x: Fraction(x, 1), nums))
