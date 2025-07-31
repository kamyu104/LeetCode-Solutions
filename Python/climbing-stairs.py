# Time:  O(logn)
# Space: O(1)

import itertools


class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        def matrix_expo(A, K):
            result = [[int(i==j) for j in xrange(len(A))] \
                      for i in xrange(len(A))]
            while K:
                if K % 2:
                    result = matrix_mult(result, A)
                A = matrix_mult(A, A)
                K /= 2
            return result

        def matrix_mult(A, B):
            ZB = zip(*B)
            return [[sum(a*b for a, b in itertools.izip(row, col)) \
                     for col in ZB] for row in A]

        T = [[1, 1],
             [1, 0]]
        return matrix_mult([[1,  0]], matrix_expo(T, n))[0][0]  # [a0, a(-1)] * T^n


# Time:  O(n)
# Space: O(1)
class Solution2(object):
    """
    :type n: int
    :rtype: int
    """
    def climbStairs(self, n):
        prev, current = 0, 1
        for i in xrange(n):
            prev, current = current, prev + current,
        return current
        
# Time:  O(1)
# Space: O(1)
"""
As 1 <= n <= 45 we can use Binet’s Formula (Fibonacci closed form) PS: this won't work for n>70 or 100
The "climb stairs" problem is equivalent to computing the nth Fibonacci number (with a slight index shift), where:
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2)
The number of ways to climb n stairs is the (n + 1)th Fibonacci number.
"""
class Solution3:
    def climbStairs(self, n: int) -> int:
        return round((((1 + 5**0.5)/2) ** (n + 1)) / 5**0.5)
