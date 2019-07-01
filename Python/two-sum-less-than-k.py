# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def twoSumLessThanK(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        A.sort()
        result = -1
        left, right = 0, len(A)-1
        while left < right:
            if A[left]+A[right] >= K:
                right -= 1
            else:
                result = max(result, A[left]+A[right])
                left += 1
        return result
