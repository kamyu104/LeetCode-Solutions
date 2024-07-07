# Time:  O(nlogr)
# Space: O(logr)

import collections


# dp, lc3171
class Solution(object):
    def countSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result = 0
        dp = collections.defaultdict(int)
        for x in nums:
            new_dp = collections.defaultdict(int)
            if x&k == k:
                new_dp[x] += 1
                for y, c in dp.iteritems():
                    new_dp[y&x] += c
                if k in new_dp:
                    result += new_dp[k]                
            dp = new_dp
        return result
