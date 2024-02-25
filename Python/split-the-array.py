# Time:  O(n)
# Space: O(n)

import collections


# freq table
class Solution(object):
    def isPossibleToSplit(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return all(v <= 2 for v in collections.Counter(nums).itervalues())
