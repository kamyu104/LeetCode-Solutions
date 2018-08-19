# Time:  O(n)
# Spce:  O(1)

# Given an array of integers A,
# consider all non-empty subsequences of A.
# For any sequence S,
# let the width of S be the difference between
# the maximum and minimum element of S.
# Return the sum of the widths of all subsequences of A. 
# As the answer may be very large,
# return the answer modulo 10^9 + 7.
#
# Example 1:
#
# Input: [2,1,3]
# Output: 6
# Explanation:
# Subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
# The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
# The sum of these widths is 6.
#
# Note:
# - 1 <= A.length <= 20000
# - 1 <= A[i] <= 20000

class Solution(object):
    def sumSubseqWidths(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        M = 10**9+7
        # sum(A[i] * (2^i - 2^(len(A)-1-i))), i = 0..len(A)-1
        # <=>
        # sum(((A[i] - A[len(A)-1-i]) * 2^i), i = 0..len(A)-1
        result, c = 0, 1
        A.sort()
        for i in xrange(len(A)):
            result = (result + (A[i]-A[len(A)-1-i])*c % M) % M
            c = (c<<1) % M
        return result
