# Time:  O(min(mlogm, n) + nlog(log(min(mlogm, n))) + m * n) = O(nlog(log(min(m, n))) + m * n)
# Space: O(n)

# number theory, knapsack dp
class Solution(object):
    def minNumberOfPrimes(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        is_prime = [True]*(n+1)
        cnt = 0
        dp = [float("inf")]*(n+1)
        dp[0] = 0
        for i in xrange(2, n+1):
            if not is_prime[i]:
                continue
            for j in xrange(i+i, n+1, i):
                is_prime[j] = False
            for j in xrange(i, n+1):
                dp[j] = min(dp[j], dp[j-i]+1)
            cnt += 1
            if cnt == m:
                break
        return dp[n] if dp[n] != float("inf") else -1
