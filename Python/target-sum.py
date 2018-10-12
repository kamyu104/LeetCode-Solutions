# Time:  O(n * S)
# Space: O(S)

import collections


class Solution(object):
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        def subsetSum(nums, S):
            dp = collections.defaultdict(int)
            dp[0] = 1
            for n in nums:
                for i in reversed(xrange(n, S+1)):
                    if i-n in dp:
                        dp[i] += dp[i-n]
            return dp[S]

        total = sum(nums)
        if total < S or (S + total) % 2: return 0
        P = (S + total) // 2
        return subsetSum(nums, P)

