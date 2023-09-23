# Time:  O(n)
# Space: O(n)

import collections


# freq table, constructive algorithms
class Solution(object):
    def minLengthAfterRemovals(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mx = max(collections.Counter(nums).itervalues())
        return mx-(len(nums)-mx) if mx > (len(nums)-mx) else len(nums)%2
