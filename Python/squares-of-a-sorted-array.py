# Time:  O(n)
# Space: O(1)

class Solution(object):
    def sortedSquares(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        right = 0
        while right < len(A) and A[right] < 0:
            right += 1
        left = right-1

        result = []
        while 0 <= left and right < len(A):
            if A[left]**2 < A[right]**2:
                result.append(A[left]**2)
                left -= 1
            else:
                result.append(A[right]**2)
                right += 1

        while left >= 0:
            result.append(A[left]**2)
            left -= 1
        while right < len(A):
            result.append(A[right]**2)
            right += 1

        return result
