# Time:  O(logn)
# Space: O(1)

# math
class Solution(object):
    def sumAndMultiply(self, n):
        """
        :type n: int
        :rtype: int
        """
        def reverse(n):
            result = 0
            while n:
                n, r = divmod(n, 10)
                result = result*10+r
            return result

        total = x = 0
        while n:
            n, r = divmod(n, 10)
            total += r
            if r:
                x = x*10+r
        return reverse(x)*total
