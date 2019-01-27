# Time:  O(n^3)
# Space: O(n^2)

import collections


class Solution(object):
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
