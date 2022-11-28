# Time:  O(n * k)
# Space: O(n)

# dp
class Solution(object):
    def beautifulPartitions(self, s, k, minLength):
        """
        :type s: str
        :type k: int
        :type minLength: int
        :rtype: int
        """
        MOD = 10**9+7
        PRIMES = {'2', '3', '5', '7'}
        dp = [0]*len(s)  # dp[i] at j : number of j beautiful partitions in s[:i+1] 
        for i in xrange(minLength-1, len(s)):
            if s[0] in PRIMES and s[i] not in PRIMES:
                dp[i] = 1
        for j in xrange(2, k+1):
            new_dp = [0]*len(s)
            curr = int(j == 1)
            for i in xrange(j*minLength-1, len(s)):
                if s[i-minLength+1] in PRIMES:
                    curr = (curr+dp[i-minLength])%MOD
                if s[i] not in PRIMES:
                    new_dp[i] = curr
            dp = new_dp
        return dp[-1]
