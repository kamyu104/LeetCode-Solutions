# Time:  O(m * n)
# Space: O(1)

import operator


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

# Since there are no lakes, every pair of neighbour cells with different values is part of the perimeter
# (more precisely, the edge between them is). So just count the differing pairs, both horizontally and vertically
# (for the latter I simply transpose the grid).
    def islandPerimeter2(self, grid):
        return sum(sum(map(operator.ne, [0] + row, row + [0])) for row in grid + map(list, zip(*grid)))

