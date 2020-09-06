# Time:  O(n)
# Space: O(1)

class Solution(object):
    def diagonalSum(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        return sum(mat[i][i]+mat[~i][i] for i in xrange(len(mat))) - (mat[len(mat)//2][len(mat)//2] if len(mat)%2 == 1 else 0)
