# Time:  O(n^2)
# Space: O(n)

class Solution(object):
    def lenLongestFibSubseq(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        lookup = set(A)
        result = 2
        for i in xrange(len(A)):
            for j in xrange(i+1, len(A)):
                x, y, l = A[i], A[j], 2
                while x+y in lookup:
                    x, y, l = y, x+y, l+1
                result = max(result, l)
        return result if result > 2 else 0

