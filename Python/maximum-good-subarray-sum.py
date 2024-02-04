# Time:  O(n)
# Space: O(n)

import collections


# prefix sum
class Solution(object):
    def maximumSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        prefix = collections.defaultdict(lambda: float("inf"))
        curr = 0
        result = float("-inf")
        for x in nums:
            prefix[x] = min(prefix[x], curr)
            curr += x
            result = max(result, curr-prefix[x-k], curr-prefix[x+k])
        return result if result != float("-inf") else 0
