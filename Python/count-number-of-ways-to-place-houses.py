# Time:  O(logn)
# Space: O(1)

import itertools


# matrix exponentiation
class Solution(object):
    def countHousePlacements(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD = 10**9+7
        def matrix_mult(A, B):
            ZB = zip(*B)
            return [[sum(a*b % MOD for a, b in itertools.izip(row, col)) % MOD for col in ZB] for row in A]
 
        def matrix_expo(A, K):
            result = [[int(i == j) for j in xrange(len(A))] for i in xrange(len(A))]
            while K:
                if K % 2:
                    result = matrix_mult(result, A)
                A = matrix_mult(A, A)
                K /= 2
            return result

        T = [[1, 1],
             [1, 0]]
        return pow(matrix_mult([[1,  0]], matrix_expo(T, n+1))[0][0], 2, MOD)  # [a1, a0] * T^N

    
# Time:  O(n)
# Space: O(1)
# dp
class Solution2(object):
    def countHousePlacements(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD = 10**9+7
        prev, curr = 0, 1
        for _ in xrange(n+1):
            prev, curr = curr, (prev+curr)%MOD
        return pow(curr, 2, MOD)
