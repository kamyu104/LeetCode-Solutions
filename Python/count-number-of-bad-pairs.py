# Time:  O(n)
# Space: O(n)

import collections


# freq table
class Solution(object):
    def countBadPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = len(nums)*(len(nums)-1)//2
        cnt = collections.Counter()
        for i, x in enumerate(nums):
            result -= cnt[x-i]
            cnt[x-i] += 1
        return result
