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
        def magic(grid, r, c):
            expect = k * (k**2+1) // 2
            nums = set()
            min_num = float("inf")
            sum_diag, sum_anti = 0, 0
            for i in xrange(k):
                sum_diag += grid[r+i][c+i]
                sum_anti += grid[r+i][c+k-1-i]
                sum_r, sum_c = 0, 0
                for j in xrange(k):
                    min_num = min(min_num, grid[r+i][c+j])
                    nums.add(grid[r+i][c+j])
                    sum_r += grid[r+i][c+j]
                    sum_c += grid[r+j][c+i]
                if not (sum_r == sum_c == expect):
                    return False
            return sum_diag == sum_anti == expect and \
                len(nums) == k**2 and \
                min_num == 1

        k = 3
        result = 0
        for r in xrange(len(grid)-k+1):
            for c in xrange(len(grid[r])-k+1):
                if magic(grid, r, c):
                    result += 1
        return result
