# Time:  O(logn)
# Space: O(1)
    
class Solution(object):
    def newInteger(self, n):
        """
        :type n: int
        :rtype: int
        """
        result, base = 0, 1
        while n > 0:
            result += (n%9) * base
            n /= 9
            base *= 10
        return result
