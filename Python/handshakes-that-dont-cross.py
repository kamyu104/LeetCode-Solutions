# Time:  O(n)
# Space: O(1)

class Solution(object):
    def numberOfWays(self, num_people):
        """
        :type num_people: int
        :rtype: int
        """
        MOD = 10**9+7
        def inv(x, m):  # Euler's Theorem
            return pow(x, m-2, m)  # O(logMOD) = O(1)

        def nCr(n, k, m):
            if n-k < k:
                return nCr(n, n-k, m)
            result = 1
            for i in xrange(1, k+1):
                result = result*(n-k+i)*inv(i, m)%m
            return result

        n = num_people//2
        return nCr(2*n, n, MOD)*inv(n+1, MOD) % MOD  # Catalan number


# Time:  O(n^2)
# Space: O(n)
class Solution2(object):
    def numberOfWays(self, num_people):
        """
        :type num_people: int
        :rtype: int
        """
        MOD = 10**9+7
        dp = [0]*(num_people//2+1)
        dp[0] = 1
        for k in xrange(1, num_people//2+1):
            for i in xrange(k):
                dp[k] = (dp[k] + dp[i]*dp[k-1-i]) % MOD
        return dp[num_people//2]
