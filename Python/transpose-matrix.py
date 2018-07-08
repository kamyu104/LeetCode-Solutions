# Time:  O(r * c)
# Space: O(1)

# Given a matrix A, return the transpose of A.
#
# The transpose of a matrix is the matrix flipped over it's main diagonal,
# switching the row and column indices of the matrix.
#
# Example 1:
#
# Input: [[1,2,3],[4,5,6],[7,8,9]]
# Output: [[1,4,7],[2,5,8],[3,6,9]]
# Example 2:
#
# Input: [[1,2,3],[4,5,6]]
# Output: [[1,4],[2,5],[3,6]]
#
# Note:
# - 1 <= A.length <= 1000
# - 1 <= A[0].length <= 1000

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3


class Solution(object):
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        result = [[None] * len(A) for _ in xrange(len(A[0]))]
        for r, row in enumerate(A):
            for c, val in enumerate(row):
                result[c][r] = val
        return result


# Time:  O(r * c)
# Space: O(1)
class Solution2(object):
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        return zip(*A)
