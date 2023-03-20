# Time:  O(m * n)
# Space: O(m * n)

# hash table, simulation
class Solution(object):
    def checkValidGrid(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        if grid[0][0]:
            return False
        lookup = [None]*(len(grid)*len(grid[0]))
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                lookup[grid[i][j]] = (i, j)
        return all(sorted([abs(lookup[i+1][0]-lookup[i][0]), abs(lookup[i+1][1]-lookup[i][1])]) == [1, 2] for i in xrange(len(lookup)-1))

    
# Time:  O(m * n)
# Space: O(m * n)
# hash table, simulation
class Solution2(object):
    def checkValidGrid(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        lookup = {grid[i][j]:(i, j) for i in xrange(len(grid)) for j in xrange(len(grid[0]))}
        return grid[0][0] == 0 and all(sorted([abs(lookup[i+1][0]-lookup[i][0]), abs(lookup[i+1][1]-lookup[i][1])]) == [1, 2] for i in xrange(len(lookup)-1))
