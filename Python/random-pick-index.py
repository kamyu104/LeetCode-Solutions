# Time:  ctor: O(n)
#        pick: O(1)
# Space: O(n)

from random import randint
import collections


class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.__lookup = collections.defaultdict(list)
        for i, x in enumerate(nums):
            self.__lookup[x].append(i)

    def pick(self, target):
        """
        :type target: int
        :rtype: int
        """
        return self.__lookup[target][randint(0, len(self.__lookup[target])-1)]


# Time:  ctor: O(1)
#        pick: O(n)
# Space: O(1)
from random import randint


class Solution_TLE(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
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



