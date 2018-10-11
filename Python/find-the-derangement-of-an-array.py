# Time:  O(n)
# Space: O(1)

class Solution(object):
    def findDerangement(self, n):
        """
        :type n: int
        :rtype: int
        """
        M = 1000000007
        mul, total = 1, 0
        for i in reversed(xrange(n+1)):
            total = (total + M + (1 if i % 2 == 0 else -1) * mul) % M
            mul = (mul * i) % M
        return total

