# Time:  O(n)
# Space: O(m)

import collections


# freq table, prefix sum
class Solution(object):
    def countInterestingSubarrays(self, nums, modulo, k):
        """
        :type nums: List[int]
        :type modulo: int
        :type k: int
        :rtype: int
        """
        cnt = collections.Counter([0])
        result = prefix = 0
        for x in nums:
            if x%modulo == k:
                prefix = (prefix+1)%modulo
            result += cnt[(prefix-k)%modulo]
            cnt[prefix] += 1
        return result
