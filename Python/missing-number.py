# Time:  O(n)
# Space: O(1)
#
# Given an array containing n distinct numbers taken from
# 0, 1, 2, ..., n, find the one that is missing from the array.
#
# For example,
# Given nums = [0, 1, 3] return 2.
#
# Note:
# Your algorithm should run in linear runtime complexity. 
# Could you implement it using only constant extra space complexity?
#

class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return reduce(operator.xor, nums, \
                      reduce(operator.xor, xrange(len(nums) + 1)))

class Solution2(object):
    def missingNumber(self, nums):
        return sum([i for i in xrange(len(nums)+1)])-sum(nums)
