# Time:  O(n)
# Space: O(1)

class Solution(object):
    def maxTurbulenceSize(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        result = 1
        start = 0
        for i in xrange(1, len(A)):
            if i == len(A)-1 or \
               cmp(A[i-1], A[i]) * cmp(A[i], A[i+1]) != -1:
                result = max(result, i-start+1)
                start = i
        return result
