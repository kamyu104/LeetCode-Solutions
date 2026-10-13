# Time:  O(logn)
# Space: O(1)

# math
class Solution(object):
    def threeFibonacciSum(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n%2:
            return False
        a = b = 1
        while b < n//2:
            a, b = b, a+b
        return b == n//2
