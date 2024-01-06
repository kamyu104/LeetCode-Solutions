# Time:  O(n * 2^n * logn)
# Space: O(2^n)

# dp
class Solution(object):
    def selfDivisiblePermutationCount(self, n):
        """
        :type n: int
        :rtype: int
        """
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        dp = [0]*(1<<n)
        dp[0] = 1
        for i in xrange(n):
            new_dp = [0]*(1<<n)
            for mask in xrange(1<<n):
                for j in xrange(n):
                    if mask&(1<<j) and gcd(j+1, i+1) == 1:
                        new_dp[mask] += dp[mask^(1<<j)]
            dp = new_dp
        return dp[-1]
