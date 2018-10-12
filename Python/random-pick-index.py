# Time:  O(n)
# Space: O(1)

from random import randint

class Solution(object):

    def __init__(self, nums):
        """

        :type nums: List[int]
        :type numsSize: int
        """
        self.__nums = nums

    def pick(self, target):
        """
        :type target: int
        :rtype: int
        """
        reservoir = -1
        n = 0
        for i in xrange(len(self.__nums)):
            if self.__nums[i] != target:
                continue
            reservoir = i if randint(1, n+1) == 1 else reservoir
            n += 1
        return reservoir



