# Time:  O(n)
# Space: O(n)

import collections


# freq table, combinatorics
class Solution(object):
    def beautifulSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = collections.Counter()
        cnt[0] = 1
        result = curr = 0
        for x in nums:
            curr ^= x
            result += cnt[curr]
            cnt[curr] += 1
        return result
