# Time:  O(n)
# Space: O(1)

class Solution(object):
    def repeatedNTimes(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        for i in xrange(2, len(A)):
            if A[i-1] == A[i] or A[i-2] == A[i]:
                return A[i]
        return A[0]
