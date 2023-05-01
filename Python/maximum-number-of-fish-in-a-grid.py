# Time:  O(m * n)
# Space: O(m + n)

# bfs
class Solution(object):
    def findMaxFish(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        DIRECTIONS = ((1, 0), (0, 1), (-1, 0), (0, -1))
        def bfs(i, j):
            result = grid[i][j]
            grid[i][j] = 0
            q = [(i, j)]
            while q:
                new_q = []
                for i, j in q:
                    for di, dj in DIRECTIONS:
                        ni, nj = i+di, j+dj
                        if not (0 <= ni < len(grid) and
                                0 <= nj < len(grid[0]) and
                                grid[ni][nj]):
                            continue
                        result += grid[ni][nj]
                        grid[ni][nj] = 0
                        new_q.append((ni, nj))
                q = new_q
            return result

        result = 0
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if grid[i][j]:
                    result = max(result, bfs(i, j))
        return result


# Time:  O(m * n)
# Space: O(m * n)
# dfs
class Solution2(object):
    def findMaxFish(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        DIRECTIONS = ((1, 0), (0, 1), (-1, 0), (0, -1))
        def dfs(i, j):
            result = grid[i][j]
            grid[i][j] = 0
            stk = [(i, j)]
            while stk:
                i, j = stk.pop()
                for di, dj in reversed(DIRECTIONS):
                    ni, nj = i+di, j+dj
                    if not (0 <= ni < len(grid) and
                            0 <= nj < len(grid[0]) and
                            grid[ni][nj]):
                        continue
                    result += grid[ni][nj]
                    grid[ni][nj] = 0
                    stk.append((ni, nj))
            return result

        result = 0
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if grid[i][j]:
                    result = max(result, dfs(i, j))
        return result
