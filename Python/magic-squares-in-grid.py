# Time:  O(m * n)
# Space: O(1)

# A 3 x 3 magic square is a 3 x 3 grid filled with
# distinct numbers from 1 to 9 such that each row, column,
# and both diagonals all have the same sum.
#
# Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?
# (Each subgrid is contiguous).
#
# Example 1:
#
# Input: [[4,3,8,4],
#         [9,5,1,9],
#         [2,7,6,2]]
# Output: 1
# Explanation:
# The following subgrid is a 3 x 3 magic square:
# 438
# 951
# 276
#
# while this one is not:
# 384
# 519
# 762
#
# In total, there is only one magic square inside the given grid.
# Note:
# - 1 <= grid.length <= 10
# - 1 <= grid[0].length <= 10
# - 0 <= grid[i][j] <= 15

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3


class Solution(object):
    def numMagicSquaresInside(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def magic(vals):
            return (len(set(vals)) == 9 and
                    min(vals) == 1 and
                    vals[0]+vals[1]+vals[2] ==
                    vals[3]+vals[4]+vals[5] ==
                    vals[6]+vals[7]+vals[8] ==
                    vals[0]+vals[3]+vals[6] ==
                    vals[1]+vals[4]+vals[7] ==
                    vals[2]+vals[5]+vals[8] ==
                    vals[0]+vals[4]+vals[8] ==
                    vals[2]+vals[4]+vals[6] == 15)

        result = 0
        for r in xrange(len(grid)-2):
            for c in xrange(len(grid[r])-2):
                if magic([grid[r][c], grid[r][c+1], grid[r][c+2],
                          grid[r+1][c], grid[r+1][c+1], grid[r+1][c+2],
                          grid[r+2][c], grid[r+2][c+1], grid[r+2][c+2]]):
                    result += 1
        return result
