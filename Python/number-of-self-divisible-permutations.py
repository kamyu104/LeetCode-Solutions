# Time:  O(n * 2^n * logn)
# Space: O(2^n)

# bitmasks, dp
class Solution(object):
    def selfDivisiblePermutationCount(self, n):
        """
        :type n: int
        :rtype: int
        """
        def popcount(x):
            return bin(x).count('1')

        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        dp = [0]*(1<<n)
        dp[0] = 1
        for mask in xrange(1<<n):
            i = popcount(mask)
            for j in xrange(n):
                if mask&(1<<j) == 0 and gcd(j+1, i+1) == 1:
                    dp[mask|(1<<j)] += dp[mask]
        return dp[-1]
