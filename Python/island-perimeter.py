# Time:  O(m * n)
# Space: O(1)

# You are given a map in form of a two-dimensional integer grid
# where 1 represents land and 0 represents water.
# Grid cells are connected horizontally/vertically (not diagonally).
# The grid is completely surrounded by water, and there is exactly one island
# (i.e., one or more connected land cells).
# The island doesn't have "lakes" (water inside that isn't connected to
# the water around the island). One cell is a square with side length 1.
# The grid is rectangular, width and height don't exceed 100.
# Determine the perimeter of the island.
#
# Example:
#
# [[0,1,0,0],
#  [1,1,1,0],
#  [0,1,0,0],
#  [1,1,0,0]]
#
# Answer: 16


class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        count, repeat = 0, 0

        for i in xrange(len(grid)):
            for j in xrange(len(grid[i])):
                if grid[i][j] == 1:
                    count += 1
                    if i != 0 and grid[i - 1][j] == 1:
                        repeat += 1
                    if j != 0 and grid[i][j - 1] == 1:
                        repeat += 1

        return 4*count - 2*repeat
