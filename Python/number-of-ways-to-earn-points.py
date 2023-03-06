# Time:  O(n * t * c)
# Space: O(t)

# knapsack dp
class Solution(object):
    def waysToReachTarget(self, target, types):
        """
        :type target: int
        :type types: List[List[int]]
        :rtype: int
        """
        MOD = 10**9+7
        dp = [0]*(target+1)
        dp[0] = 1
        for c, m in types:
            for i in reversed(xrange(1, target+1)):
                for j in xrange(1, min(i//m, c)+1):
                    dp[i] = (dp[i]+dp[i-j*m])%MOD
        return dp[-1]


# Time:  O(n * t * c)
# Space: O(t)
# knapsack dp
class Solution2(object):
    def waysToReachTarget(self, target, types):
        """
        :type target: int
        :type types: List[List[int]]
        :rtype: int
        """
        MOD = 10**9+7
        dp = [0]*(target+1)
        dp[0] = 1
        for c, m in types:
            new_dp = [0]*(target+1)
            for i in xrange(target+1):
                for j in xrange(min((target-i)//m, c)+1):
                    new_dp[i+j*m] = (new_dp[i+j*m]+dp[i])%MOD
            dp = new_dp
        return dp[-1]
