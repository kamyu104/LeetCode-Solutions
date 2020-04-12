# Time:  O(logn)
# Space: O(1)

import itertools


class Solution(object):
    def tribonacci(self, n):
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

        T = [[1, 1, 0],
             [1, 0, 1],
             [1, 0, 0]]
        return matrix_mult([[1, 0, 0]], matrix_expo(T, n))[0][1]  # [a1, a0, a(-1)] * T^n
    
    
# Time:  O(n)
# Space: O(1)
class Solution2(object):
    def tribonacci(self, n):
        """
        :type n: int
        :rtype: int
        """
        a, b, c = 0, 1, 1
        for _ in xrange(n):
            a, b, c = b, c, a+b+c
        return a
