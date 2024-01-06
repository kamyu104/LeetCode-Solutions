# Time:  O(n^2 * logn + n * 2^n) = O(n * 2^n)
# Space: O(n^2 + 2^n) = O(2^n)

# bitmasks, dp, memoization
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

        lookup = [[0]*n for _ in xrange(n)]
        def memoization(a, b):
            if not lookup[a-1][b-1]:
                lookup[a-1][b-1] = gcd(a, b)
            return lookup[a-1][b-1]

        dp = [0]*(1<<n)
        dp[0] = 1
        for mask in xrange(1<<n):
            i = popcount(mask)
            for j in xrange(n):
                if mask&(1<<j) == 0 and memoization(j+1, i+1) == 1:
                    dp[mask|(1<<j)] += dp[mask]
        return dp[-1]
