# Time:  O(n * k)
# Space: O(k)

class Solution(object):
    def maxSumAfterPartitioning(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        W = K+1
        dp = [0]*W
        for i in xrange(len(A)):
            curr_max = 0
            # dp[i % W] = 0;  # no need in this problem
            for k in xrange(1, min(K, i+1) + 1):
                curr_max = max(curr_max, A[i-k+1])
                dp[i % W] = max(dp[i % W], (dp[(i-k) % W] if i >= k else 0) + curr_max*k)
        return dp[(len(A)-1) % W]
