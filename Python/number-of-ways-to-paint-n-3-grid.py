# Time:  O(logn)
# Space: O(1)

import itertools


class Solution(object):
    def numOfWays(self, n):
        """
        :type n: int
        :rtype: int
        """
        def matrix_expo(A, K):
            result = [[int(i==j) for j in xrange(len(A))]
                       for i in xrange(len(A))]
            while K:
                if K % 2:
                    result = matrix_mult(result, A)
                A = matrix_mult(A, A)
                K /= 2
            return result

        def matrix_mult(A, B):
            ZB = zip(*B)
            return [[sum(a*b % MOD for a, b in itertools.izip(row, col)) % MOD
                     for col in ZB] for row in A]
        
        MOD = 10**9 + 7
        T = [[3, 2],
             [2, 2]]
        return sum(matrix_mult([[6, 6]], matrix_expo(T, n-1))[0]) % MOD  # [a1, a0] * T^(n-1)


# Time:  O(n)
# Space: O(1)
class Solution2(object):
    def numOfWays(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD = 10**9 + 7
        aba, abc = 6, 6
        for _ in xrange(n-1):
            aba, abc = (3*aba%MOD + 2*abc%MOD)%MOD, \
                       (2*abc%MOD + 2*aba%MOD)%MOD
        return (aba+abc)%MOD
