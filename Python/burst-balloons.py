# Time:  O(n^3)
# Space: O(n^2)


class Solution(object):
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        coins = [1] + [i for i in nums if i > 0] + [1]
        n = len(coins)
        max_coins = [[0 for _ in xrange(n)] for _ in xrange(n)]

        for k in xrange(2, n):
            for left in xrange(n - k):
                right = left + k
                for i in xrange(left + 1, right):
                    max_coins[left][right] = \
                        max(max_coins[left][right],
                            coins[left] * coins[i] * coins[right] +
                            max_coins[left][i] +
                            max_coins[i][right])

        return max_coins[0][-1]

