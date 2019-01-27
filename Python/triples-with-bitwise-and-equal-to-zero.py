# Time:  O(nlogn), n is the max of A
# Space: O(n)

import collections


# https://blog.csdn.net/john123741/article/details/76576925
# FWT solution
class Solution(object):
    def countTriplets(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        def FWT(A):
            B = A[:]
            d = 1
            while d < len(B):
                for i in xrange(0, len(B), d << 1):
                    for j in xrange(d):
                        B[i+j] = B[i+j] + B[i+j+d]
                d <<= 1
            return B

        def UFWT(A):
            B = A[:]
            d = 1
            while d < len(B):
                for i in xrange(0, len(B), d << 1):
                    for j in xrange(d):
                        B[i+j] = B[i+j] - B[i+j+d]
                d <<= 1
            return B

        n, max_A = 1, max(A)
        while n <= max_A:
            n *= 2
        count = collections.Counter(A)
        B = [count[i] for i in xrange(n)]
        C = UFWT([x**3 for x in FWT(B)])
        return C[0]


# Time:  O(n^3), n is the length of A
# Space: O(n^2)
import collections


class Solution2(object):
    def countTriplets(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        count = collections.defaultdict(int)
        for i in xrange(len(A)):
            for j in xrange(len(A)):
                count[A[i]&A[j]] += 1
        result = 0
        for k in xrange(len(A)):
            for v in count:
                if A[k]&v == 0:
                    result += count[v]
        return result
