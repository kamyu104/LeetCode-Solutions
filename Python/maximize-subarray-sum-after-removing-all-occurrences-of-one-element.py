# Time:  O(n)
# Space: O(n)

import collections


# hash table, greedy, kadane's algorithm
class Solution(object):
    def maxSubarraySum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = float("-inf")
        curr = mn = mn0 = 0
        mn1 = collections.defaultdict(int)
        for x in nums:
            curr += x
            result = max(result, curr-mn)
            mn1[x] = min(mn1[x], mn0)+x
            mn0 = min(mn0, curr)
            mn = min(mn, mn1[x], mn0)
        return result
