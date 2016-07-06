# Time:  O(logn * nlogx * logx) = O(1)
# Space: O(nlogx) = O(1)

# Implement pow(x, n).

class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        result = 1
        abs_n = abs(n)
        while abs_n:
            if abs_n & 1:
                result *= x
            abs_n >>= 1
            x *= x

        return 1 / result if n < 0 else result


# Time:  O(logn * nlogx * logx) = O(1)
# Space: O(nlogx) = O(1)
class Solution2(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n < 0 and n != -n:
            return 1.0 / self.myPow(x, -n)
        if n == 0:
            return 1
        v = self.myPow(x, n / 2)
        if n % 2 == 0:
            return v * v
        else:
            return v * v * x


if __name__ == "__main__":
    print Solution().pow(3, 5)
    print Solution().pow(3, -5)
