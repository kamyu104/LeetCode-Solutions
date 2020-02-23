# Time:  O(n)
# Space: O(1)

class Solution(object):
    def countOrders(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD = 10**9+7
        result = 1
        for i in reversed(xrange(2, 2*n+1, 2)):
            result = result * i*(i-1)//2 % MOD
        return result
