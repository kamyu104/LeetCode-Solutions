# Time:  O(m * n)
# Space: O(m + n)

# dp
class Solution(object):
    def isPossibleToCutPath(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if (i, j) == (0, 0) or grid[i][j] == 0:
                    continue
                if (i-1 < 0 or grid[i-1][j] == 0) and (j-1 < 0 or grid[i][j-1] == 0):
                    grid[i][j] = 0
        for i in reversed(xrange(len(grid))):
            for j in reversed(xrange(len(grid[0]))):
                if (i, j) == (len(grid)-1, len(grid[0])-1) or grid[i][j] == 0:
                    continue
                if (i+1 >= len(grid) or grid[i+1][j] == 0) and (j+1 >= len(grid[0]) or grid[i][j+1] == 0):
                    grid[i][j] = 0
        cnt = [0]*(len(grid)+len(grid[0])-1)
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                cnt[i+j] += grid[i][j]
        return any(cnt[i] <= 1 for i in xrange(1, len(grid)+len(grid[0])-2))


# Time:  O(m * n)
# Space: O(m + n)
# iterative dfs
class Solution2(object):
    def isPossibleToCutPath(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        def iter_dfs():
            stk = [(0, 0)]
            while stk:
                i, j = stk.pop()
                if not (i < len(grid) and j < len(grid[0]) and grid[i][j]):
                    continue
                if (i, j) == (len(grid)-1, len(grid[0])-1):
                    return True
                if (i, j) != (0, 0):
                    grid[i][j] = 0
                stk.append((i, j+1))
                stk.append((i+1, j))  
            return False

        return not iter_dfs() or not iter_dfs()


# Time:  O(m * n)
# Space: O(m + n)
# dfs
class Solution3(object):
    def isPossibleToCutPath(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        def dfs(i, j):
            if not (i < len(grid) and j < len(grid[0]) and grid[i][j]):
                return False
            if (i, j) == (len(grid)-1, len(grid[0])-1):
                return True
            if (i, j) != (0, 0):
                grid[i][j] = 0
            return dfs(i+1, j) or dfs(i, j+1)

        return not dfs(0, 0) or not dfs(0, 0)
