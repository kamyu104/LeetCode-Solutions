# Time:  O(logn)
# Space: O(1)

# math
class Solution(object):
    def alternateDigitSum(self, n):
        """
        :type n: int
        :rtype: int
        """
        result = 0
        sign = 1
        while n:
            sign *= -1
            result += sign*(n%10)
            n //= 10
        return sign*result
