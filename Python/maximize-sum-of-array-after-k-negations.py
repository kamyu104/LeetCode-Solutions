# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def largestSumAfterKNegations(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        A.sort()
        i = 0
        while i < len(A) and i < K and A[i] < 0:
            A[i] = -A[i]
            i += 1
        return sum(A) - ((K-i)%2)*min(A)*2
