# Time:  O(n)
# Space: O(1)

import bisect


class Solution(object):
    def sortedSquares(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        right = bisect.bisect_left(A, 0)
        left = right-1
        result = []
        while 0 <= left or right < len(A):
            if right == len(A) or \
               (0 <= left and A[left]**2 < A[right]**2):
                result.append(A[left]**2)
                left -= 1
            else:
                result.append(A[right]**2)
                right += 1
        return result
