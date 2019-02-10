# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def brokenCalc(self, X, Y):
        """
        :type X: int
        :type Y: int
        :rtype: int
        """
        result = 0
        while X < Y:
            if Y%2:
                Y += 1
            else:
                Y /= 2
            result += 1
        return result + X-Y
