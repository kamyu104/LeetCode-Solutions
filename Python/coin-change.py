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
        amounts = [INF] * (amount + 1)
        amounts[0] = 0
        for i in xrange(amount + 1):
            if amounts[i] != INF:
                for coin in coins:
                    if i + coin <= amount:
                        amounts[i + coin] = min(amounts[i + coin], amounts[i] + 1)
        return amounts[amount] if amounts[amount] != INF else -1


