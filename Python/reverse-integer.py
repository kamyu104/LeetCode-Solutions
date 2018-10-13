# Time:  O(logn) = O(1)
# Space: O(1)

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 0:
            return -self.reverse(-x)

        result = 0
        while x:
            result = result * 10 + x % 10
            x //= 10
        return result if result <= 0x7fffffff else 0  # Handle overflow.

    def reverse2(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 0:
            x = int(str(x)[::-1][-1] + str(x)[::-1][:-1])
        else:
            x = int(str(x)[::-1])
        x = 0 if abs(x) > 0x7FFFFFFF else x
        return x

    def reverse3(self, x):
        """
        :type x: int
        :rtype: int
        """
        s = cmp(x, 0)
        r = int(repr(s * x)[::-1])
        return s * r * (r < 2 ** 31)


