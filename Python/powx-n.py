# Time:  O(logn)
# Space: O(1)
# 
# Implement pow(x, n).
#

class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        res = 1
        abs_n = abs(n)
        while abs_n:
            if abs_n & 1:
                res *= x
            abs_n >>= 1
            x *= x

        return 1 / res if n < 0 else res


if __name__ == "__main__":
    print Solution().pow(3, 5)
    print Solution().pow(3, -5)
