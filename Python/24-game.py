# Time:  O(n^3 * 4^n) = O(1), n = 4
# Space: O(n^2) = O(1)

# You have 4 cards each containing a number from 1 to 9.
# You need to judge whether they could operated through *, /, +, -, (, ) to get the value of 24.
#
# Example 1:
# Input: [4, 1, 8, 7]
# Output: True
# Explanation: (8-4) * (7-1) = 24
# Example 2:
# Input: [1, 2, 1, 2]
# Output: False
# Note:
# The division operator / represents real division, not integer division.
# For example, 4 / (1 - 2/3) = 12.
# Every operation done is between two numbers. In particular, we cannot use - as a unary operator.
# For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
# You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.

from operator import add, sub, mul, truediv

class Solution(object):
    def judgePoint24(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) == 1:
            return abs(nums[0]-24) < 1e-6
        ops = [add, sub, mul, truediv]
        for i in xrange(len(nums)):
            for j in xrange(len(nums)):
                if i == j:
                    continue
                next_nums = [nums[k] for k in xrange(len(nums)) if k not in [i, j]]
                for op in ops:
                    if ((op is add or op is mul) and j > i) or \
                       (op == truediv and nums[j] == 0):
                            continue
                    next_nums.append(op(nums[i], nums[j]))
                    if self.judgePoint24(next_nums):
                        return True
                    next_nums.pop()
        return False


# Time:  O(n^3 * 4^n) = O(1), n = 4
# Space: O(n^2) = O(1)
from fractions import Fraction
from operator import add, sub, mul, div

class Solution2(object):
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
                    next_nums = [nums[k] for k in xrange(len(nums)) if k not in [i, j]]
                    for op in ops:
                        if (op is add or op is mul) and j > i: continue
                        if op == div and nums[j] == 0: continue
                        next_nums.append(op(nums[i], nums[j]))
                        if dfs(next_nums):
                            return True
                        next_nums.pop()
            return False

        return dfs(map(Fraction, nums))
