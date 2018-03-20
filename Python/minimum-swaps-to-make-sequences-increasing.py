# Time:  O(n)
# Space: O(1)

# We have two integer sequences A and B of the same non-zero length.
#
# We are allowed to swap elements A[i] and B[i].
# Note that both elements are in the same index position in their respective sequences.
#
# At the end of some number of swaps, A and B are both strictly increasing.
# (A sequence is strictly increasing if and only if A[0] < A[1] < A[2] < ... < A[A.length - 1].)
#
# Given A and B, return the minimum number of swaps to make both sequences strictly increasing.
# It is guaranteed that the given input always makes it possible.
#
# Example:
# Input: A = [1,3,5,4], B = [1,2,3,7]
# Output: 1
# Explanation: 
# Swap A[3] and B[3].  Then the sequences are:
# A = [1, 3, 5, 7] and B = [1, 2, 3, 4]
# which are both strictly increasing.
#
# Note:
# - A, B are arrays with the same length, and that length will be in the range [1, 1000].
# - A[i], B[i] are integer values in the range [0, 2000].

class Solution(object):
    def minSwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        dp_no_swap, dp_swap = [0]*2, [1]*2
        for i in xrange(1, len(A)):
            dp_no_swap[i%2], dp_swap[i%2] = float("inf"), float("inf")
            if A[i-1] < A[i] and B[i-1] < B[i]:
                dp_no_swap[i%2] = min(dp_no_swap[i%2], dp_no_swap[(i-1)%2])
                dp_swap[i%2] = min(dp_swap[i%2], dp_swap[(i-1)%2]+1)
            if A[i-1] < B[i] and B[i-1] < A[i]:
                dp_no_swap[i%2] = min(dp_no_swap[i%2], dp_swap[(i-1)%2])
                dp_swap[i%2] = min(dp_swap[i%2], dp_no_swap[(i-1)%2]+1)
        return min(dp_no_swap[(len(A)-1)%2], dp_swap[(len(A)-1)%2])
