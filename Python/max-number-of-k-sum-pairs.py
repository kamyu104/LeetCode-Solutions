# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def maxOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        count = collections.Counter()
        result = 0
        for x in nums:
            if k-x in count and count[k-x]:
                count[k-x] -= 1
                result += 1
            else:
                count[x] += 1
        return result
