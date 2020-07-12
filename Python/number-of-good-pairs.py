# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def numIdenticalPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(c*(c-1)//2 for c in collections.Counter(nums).itervalues())
