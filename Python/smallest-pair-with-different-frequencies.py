# Time:  O(n)
# Space: O(n)

import collections


# freq table
class Solution(object):
    def minDistinctFreqPair(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        INF = float("inf")
        cnt = collections.defaultdict(int)
        for x in nums:
            cnt[x] += 1
        x = min(nums)
        mn = INF
        for y in nums:
            if cnt[y] != cnt[x]:
                mn = min(mn, y)
        return [x, mn] if mn is not INF else [-1, -1]
