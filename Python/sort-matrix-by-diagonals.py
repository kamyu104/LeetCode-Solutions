# Time:  O(n^2 * logn)
# Space: O(n^2)

# sort
class Solution(object):
    def sortMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        lookup = [[] for _ in xrange((len(grid)-1)+(len(grid[0])-1)-(0-(len(grid[0])-1))+1)]
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                lookup[i-j].append(grid[i][j])
        for i in xrange(0-(len(grid[0])-1), (len(grid)-1)+(len(grid[0])-1)+1):
            if i < 0:
                lookup[i].sort(reverse=True)
            else:
                lookup[i].sort()
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                grid[i][j] = lookup[i-j].pop()
        return grid
