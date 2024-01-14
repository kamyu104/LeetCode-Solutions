# Time:  O(n)
# Space: O(n)

import collections


# freq table
class Solution(object):
    def maxFrequencyElements(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = collections.Counter(nums)
        mx = max(cnt.itervalues())
        return sum(v for v in cnt.itervalues() if v == mx)
