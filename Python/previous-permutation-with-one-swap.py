# Time:  O(n)
# Space: O(1)

class Solution(object):
    def prevPermOpt1(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        for left in reversed(xrange(len(A)-1)):
            if A[left] > A[left+1]:
                break
        else:
            return A
        right = len(A)-1
        while A[left] <= A[right]:
            right -= 1
        while A[right-1] == A[right]:
            right -= 1
        A[left], A[right] = A[right], A[left]
        return A
