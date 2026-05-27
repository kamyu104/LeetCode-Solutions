# Time:  O(n * m)
# Space: O(1)

import itertools


# kadane's algorithm
class Solution(object):
    def maxScore(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def modified_kadane(l, get):
            result = curr = get(0)+get(1)
            for i in xrange(2, l):
                curr = max(curr, get(i-1))+get(i)
                result = max(result, curr)
            return result
        
        return max(
            max(modified_kadane(len(grid[0]), lambda x: grid[i][x]) for i in xrange(len(grid))),
            max(modified_kadane(len(grid), lambda x: grid[x][j]) for j in xrange(len(grid[0]))),
            max(itertools.chain((grid[i][j] for i in xrange(1, len(grid)-1) for j in xrange(1, len(grid[0])-1)), (float("-inf"),)))
        )
