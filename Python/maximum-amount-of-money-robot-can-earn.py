# Time:  O(m * n * k) = O(m * n)
# Space: O(min(m, n) * k) = O(min(m, n))

# dp
class Solution(object):
    def maximumAmount(self, coins):
        """
        :type coins: List[List[int]]
        :rtype: int
        """
        K = 2
        mn = min(len(coins), len(coins[0]))
        mx = max(len(coins), len(coins[0]))
        get = (lambda i, j: coins[i][j]) if len(coins) == mx else (lambda i, j: coins[j][i])
        dp = [[float("-inf")]*(K+1) for _ in xrange(mn)] 
        for i in xrange(mx):
            new_dp = [[float("-inf")]*(K+1) for _ in xrange(mn)]
            for j in xrange(mn):
                for k in xrange(K+1):
                    if i == 0 and j == 0:
                        new_dp[j][k] = max(get(i, j), 0) if k-1 >= 0 else get(i, j)
                        continue
                    if i-1 >= 0:
                        new_dp[j][k] = max(new_dp[j][k], dp[j][k]+get(i, j))
                        if k-1 >= 0:
                            new_dp[j][k] = max(new_dp[j][k], dp[j][k-1])
                    if j-1 >= 0:
                        new_dp[j][k] = max(new_dp[j][k], new_dp[j-1][k]+get(i, j))
                        if k-1 >= 0:
                            new_dp[j][k] = max(new_dp[j][k], new_dp[j-1][k-1])
            dp = new_dp
        return dp[-1][-1]


# Time:  O(m * n * k) = O(m * n)
# Space: O(n * k) = O(n)
# dp
class Solution2(object):
    def maximumAmount(self, coins):
        """
        :type coins: List[List[int]]
        :rtype: int
        """
        K = 2
        dp = [[float("-inf")]*(K+1) for _ in xrange(len(coins[0]))] 
        for i in xrange(len(coins)):
            new_dp = [[float("-inf")]*(K+1) for _ in xrange(len(coins[0]))]
            for j in xrange(len(coins[0])):
                for k in xrange((K+1)):
                    if i == 0 and j == 0:
                        new_dp[j][k] = max(coins[i][j], 0) if k-1 >= 0 else coins[i][j]
                        continue
                    if i-1 >= 0:
                        new_dp[j][k] = max(new_dp[j][k], dp[j][k]+coins[i][j])
                        if k-1 >= 0:
                            new_dp[j][k] = max(new_dp[j][k], dp[j][k-1])
                    if j-1 >= 0:
                        new_dp[j][k] = max(new_dp[j][k], new_dp[j-1][k]+coins[i][j])
                        if k-1 >= 0:
                            new_dp[j][k] = max(new_dp[j][k], new_dp[j-1][k-1])
            dp = new_dp
        return dp[-1][-1]
