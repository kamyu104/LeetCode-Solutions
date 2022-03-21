# Time:  O(n)
# Space: O(n)

import collections


# freq table
class Solution(object):
    def divideArray(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return all(cnt%2 == 0 for cnt in collections.Counter(nums).itervalues())
