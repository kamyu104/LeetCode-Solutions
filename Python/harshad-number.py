# Time:  O(logx)
# Space: O(1)

# math
class Solution(object):
    def sumOfTheDigitsOfHarshadNumber(self, x):
        """
        :type x: int
        :rtype: int
        """
        result = 0
        y = x
        while y:
            y, r = divmod(y, 10)
            result += r
        return result if x%result == 0 else -1
