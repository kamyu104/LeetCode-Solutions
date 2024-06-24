# Time:  O(n * k)
# Space: O(k)

# dp, combinatorics, sliding window, two pointers
class Solution(object):
    def kInversePairs(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        dp = [1]
        for i in xrange(n):
            new_dp = [0]*min(len(dp)+((i+1)-1), k+1)
            for j in xrange(len(new_dp)):
                new_dp[j] = dp[j] if j < len(dp) else 0
                if j-1 >= 0:
                    new_dp[j] = (new_dp[j]+new_dp[j-1])%MOD
                if j-(i+1) >= 0:
                    new_dp[j] = (new_dp[j]-dp[j-(i+1)])%MOD
            dp = new_dp
        return dp[k] if k < len(dp) else 0


# Time:  O(n * k)
# Space: O(k)
# dp, combinatorics, sliding window, two pointers
class Solution2(object):
    def kInversePairs(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        dp = [0]*(k+1)
        dp[0] = 1
        for i in xrange(n):
            new_dp = [0]*len(dp)
            for j in xrange(len(dp)):
                new_dp[j] = dp[j]
                if j-1 >= 0:
                    new_dp[j] = (new_dp[j]+new_dp[j-1])%MOD
                if j-(i+1) >= 0:
                    new_dp[j] = (new_dp[j]-dp[j-(i+1)])%MOD
            dp = new_dp
        return dp[k]


# Time:  O(n * k)
# Space: O(k)
# dp, combinatorics, sliding window, two pointers
class Solution3(object):
    def kInversePairs(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        dp = [0]*(k+1)
        dp[0] = 1
        for i in xrange(n):
            new_dp = [0]*len(dp)
            curr = 0
            for j in xrange(len(dp)):
                curr = (curr+dp[j])%MOD
                if j-(i+1) >= 0:
                    curr = (curr-dp[j-(i+1)])%MOD
                new_dp[j] = curr
            dp = new_dp
        return dp[-1]

