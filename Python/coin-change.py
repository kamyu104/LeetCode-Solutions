# Time:  O(n * k), n is the number of coins, k is the amount of money
# Space: O(k)

class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        INF = 0x7fffffff  # Using float("inf") would be slower.
        dp = [INF] * (amount + 1)
        dp[0] = 0
        for i in xrange(amount + 1):
            if dp[i] != INF:
                for coin in coins:
                    if i + coin <= amount:
                        dp[i + coin] = min(dp[i + coin], dp[i] + 1)
        return dp[amount] if dp[amount] != INF else -1


