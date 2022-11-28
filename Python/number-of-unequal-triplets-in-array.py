# Time:  O(n)
# Space: O(1)

# dp, freq table
class Solution(object):
    def unequalTriplets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        K = 3
        cnt = collections.Counter()
        dp = [0]*K  # dp[i]: number of unequal (i+1)-plets 
        for x in nums:
            other_cnt = 1
            for i in xrange(K):
                dp[i], other_cnt = dp[i]+other_cnt, dp[i]-cnt[x]*other_cnt
            cnt[x] += 1
        return dp[K-1]
