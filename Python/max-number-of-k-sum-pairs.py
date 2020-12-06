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
        lookup = collections.Counter()
        for num in nums:
            lookup[num] += 1
        result = 0
        for num, cnt in lookup.iteritems():
            if k-num == num:
                result += cnt//2
            elif k-num in lookup:
                cnt = min(cnt, lookup[k-num])
                result += cnt
                lookup[num] -= cnt
                lookup[k-num] -= cnt
        return result
