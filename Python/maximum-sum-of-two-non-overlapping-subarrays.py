# Time:  O(n)
# Space: O(1)

class Solution(object):
    def maxSumTwoNoOverlap(self, A, L, M):
        """
        :type A: List[int]
        :type L: int
        :type M: int
        :rtype: int
        """
        for i in xrange(1, len(A)):
            A[i] += A[i-1]
        result, L_max, M_max = A[L+M-1], A[L-1], A[M-1]
        for i in xrange(L+M, len(A)):
            L_max = max(L_max, A[i-M] - A[i-L-M])
            M_max = max(M_max, A[i-L] - A[i-L-M])
            result = max(result,
                         L_max + A[i] - A[i-M],
                         M_max + A[i] - A[i-L])
        return result
