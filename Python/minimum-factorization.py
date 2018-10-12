# Time:  O(loga)
# Space: O(1)

class Solution(object):
    def smallestFactorization(self, a):
        """
        :type a: int
        :rtype: int
        """
        if a < 2:
            return a
        result, mul = 0, 1
        for i in reversed(xrange(2, 10)):
            while a % i == 0:
                a /= i
                result = mul*i + result
                mul *= 10
        return  result if a == 1 and result < 2**31 else 0


