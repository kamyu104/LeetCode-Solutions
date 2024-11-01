# Time:  O(n + 26^3 * logt)
# Space: O(26^2)

import itertools


# matrix fast exponentiation
class Solution(object):
    def lengthAfterTransformations(self, s, t, nums):
        """
        :type s: str
        :type t: int
        :type nums: List[int]
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

        cnt = [0]*26
        for x in s:
            cnt[ord(x)-ord('a')] += 1
        matrix = [[0]*26 for _ in xrange(26)]
        for i in xrange(len(nums)):
            for j in xrange(1, nums[i]+1):
                matrix[i][(i+j)%26] = 1
        matrix_pow_t = matrix_expo(matrix, t)
        return reduce(lambda accu, x: (accu+x)%MOD, matrix_mult([cnt], matrix_pow_t)[0], 0)
