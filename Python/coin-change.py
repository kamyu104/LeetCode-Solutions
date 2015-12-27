# Time:  O(n * k), n is the number of coins, k is the amount of money
# Space: O(k)
#
# You are given coins of different denominations and
# a total amount of money amount. Write a function to
# compute the fewest number of coins that you need to
# make up that amount. If that amount of money cannot
# be made up by any combination of the coins, return -1.
#
# Example 1:
# coins = [1, 2, 5], amount = 11
# return 3 (11 = 5 + 5 + 1)
#
# Example 2:
# coins = [2], amount = 3
# return -1.
#
# Note:
# You may assume that you have an infinite number of each kind of coin.

# DP solution. (1680ms)
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        INF = 0x7ffffffe  # Using float("int") would be slower.
        amounts = [INF] * (amount + 1)
        amounts[0] = 0
        for i in xrange(amount + 1):
            if amounts[i] != INF:
                for coin in coins:
                    if i + coin <= amount:
                        amounts[i + coin] = min(amounts[i + coin], amounts[i] + 1)
        return amounts[amount] if amounts[amount] != INF else -1
  
