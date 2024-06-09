# Time:  O(n * k)
# Space: O(n * k)

import collections


# dp
class Solution(object):
    def maximumLength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        lookup = {x:i for i, x in enumerate(set(nums))}
        dp = [[0]*len(lookup) for _ in xrange(k+1)]
        result = [0]*(k+1)
        for x in nums:
            x = lookup[x]
            for i in reversed(xrange(k+1)):
                dp[i][x] = max(dp[i][x], result[i-1] if i-1 >= 0 else 0)+1
                result[i] = max(result[i], dp[i][x])
        return result[k]


# Time:  O(n * k)
# Space: O(n * k)
import collections


# dp
class Solution2(object):
    def maximumLength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        dp = [collections.defaultdict(int) for _ in xrange(k+1)]
        result = [0]*(k+1)
        for x in nums:
            for i in reversed(xrange(k+1)):
                dp[i][x] = max(dp[i][x], result[i-1] if i-1 >= 0 else 0)+1
                result[i] = max(result[i], dp[i][x])
        return result[k]
