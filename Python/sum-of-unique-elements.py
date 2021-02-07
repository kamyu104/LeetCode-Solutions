# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def sumOfUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(x for x, c in collections.Counter(nums).iteritems() if c == 1)
