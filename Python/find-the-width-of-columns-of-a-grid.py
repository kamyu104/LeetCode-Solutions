# Time:  O(m * n)
# Space: O(1)

# array
class Solution(object):
    def findColumnWidth(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[int]
        """
        def length(x):
            l = 1
            if x < 0:
                x = -x
                l += 1
            while x >= 10:
                x //= 10
                l += 1
            return l

        return [max(length(grid[i][j]) for i in xrange(len(grid))) for j in xrange(len(grid[0]))]


# Time:  O(m * n)
# Space: O(logr)
# array
class Solution2(object):
    def findColumnWidth(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[int]
        """
        return [max(len(str(grid[i][j])) for i in xrange(len(grid))) for j in xrange(len(grid[0]))]


# Time:  O(m * n)
# Space: O(m + logr)
import itertools


# array
class Solution3(object):
    def findColumnWidth(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[int]
        """
        return [max(len(str(x)) for x in col) for col in itertools.izip(*grid)]
