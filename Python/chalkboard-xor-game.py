# Time:  O(n)
# Space: O(1)

from operator import xor
from functools import reduce


class Solution(object):
    def xorGame(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return reduce(xor, nums) == 0 or \
            len(nums) % 2 == 0

