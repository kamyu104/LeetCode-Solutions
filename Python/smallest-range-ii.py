# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def smallestRangeII(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        A.sort()
        result = A[-1]-A[0]
        for i in xrange(len(A)-1):
            result = min(result,
                         max(A[-1]-K, A[i]+K) -
                         min(A[0]+K, A[i+1]-K))
        return result

