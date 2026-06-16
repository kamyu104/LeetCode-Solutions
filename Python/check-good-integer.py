# Time:  O(logn)
# Space: O(1)

# math
class Solution(object):
    def checkGoodInteger(self, n):
        """
        :type n: int
        :rtype: bool
        """
        result = 0
        while n:
            n, r = divmod(n, 10)
            result += r*r-r
        return result >= 50
