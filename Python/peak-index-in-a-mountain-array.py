# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def peakIndexInMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        left, right = 0, len(A)
        while left < right:
            mid = left + (right-left)//2
            if A[mid] > A[mid+1]:
                right = mid
            else:
                left = mid+1
        return left

