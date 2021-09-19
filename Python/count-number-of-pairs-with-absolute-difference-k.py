# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def countKDifference(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        lookup = collections.defaultdict(int)
        result = 0
        for x in nums:
            if x-k in lookup:
                result += lookup[x-k]
            if x+k in lookup:
                result += lookup[x+k]
            lookup[x] += 1            
        return result
