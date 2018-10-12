# Time:  O(logn), pow is O(logn).
# Space: O(1)

class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 4:
            return n - 1

        #  Proof.
        #  1. Let n = a1 + a2 + ... + ak, product = a1 * a2 * ... * ak
        #      - For each ai >= 4, we can always maximize the product by:
        #        ai <= 2 * (ai - 2)
        #      - For each aj >= 5, we can always maximize the product by:
        #        aj <= 3 * (aj - 3)
        #
        #     Conclusion 1:
        #      - For n >= 4, the max of the product must be in the form of
        #        3^a * 2^b, s.t. 3a + 2b = n
        #
        #  2. To maximize the product = 3^a * 2^b s.t. 3a + 2b = n
        #      - For each b >= 3, we can always maximize the product by:
        #        3^a * 2^b <= 3^(a+2) * 2^(b-3) s.t. 3(a+2) + 2(b-3) = n
        #
        #     Conclusion 2:
        #      - For n >= 4, the max of the product must be in the form of
        #        3^Q * 2^R, 0 <= R < 3 s.t. 3Q + 2R = n
        #        i.e.
        #          if n = 3Q + 0,   the max of the product = 3^Q * 2^0
        #          if n = 3Q + 2,   the max of the product = 3^Q * 2^1
        #          if n = 3Q + 2*2, the max of the product = 3^Q * 2^2

        res = 0
        if n % 3 == 0:            #  n = 3Q + 0, the max is 3^Q * 2^0
            res = 3 ** (n // 3)
        elif n % 3 == 2:          #  n = 3Q + 2, the max is 3^Q * 2^1
            res = 3 ** (n // 3) * 2
        else:                     #  n = 3Q + 4, the max is 3^Q * 2^2
            res = 3 ** (n // 3 - 1) * 4
        return res


# Time:  O(n)
# Space: O(1)
# DP solution.
class Solution2(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 4:
            return n - 1

        # integerBreak(n) = max(integerBreak(n - 2) * 2, integerBreak(n - 3) * 3)
        res = [0, 1, 2, 3]
        for i in xrange(4, n + 1):
            res[i % 4] = max(res[(i - 2) % 4] * 2, res[(i - 3) % 4] * 3)
        return res[n % 4]

