# Time:  O(n)
# Space: O(n)

import collections


# freq table, greedy
class Solution(object):
    def minCost(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        cnt = collections.defaultdict(int)
        for x in nums1:
            cnt[x] += 1
        for x in nums2:
            cnt[x] -= 1
        result = 0
        for c in cnt.itervalues():
            if c%2:
                return -1
            if c//2 > 0:
                result += c//2 
        return result
