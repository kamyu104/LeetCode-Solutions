# Time:  O(n^2)
# Space: O(n^2)

# flood fill, bfs, math
class Solution(object):
    def sumRemoteness(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        DIRECTIONS = ((1, 0), (0, 1), (-1, 0), (0, -1))
        def bfs(i, j):
            total, cnt = grid[i][j], 1
            grid[i][j] = -1
            q = [(i, j)]
            while q:
                new_q = []
                for i, j in q:
                    for di, dj in DIRECTIONS:
                        ni, nj = i+di, j+dj
                        if not (0 <= ni < len(grid) and 0 <= nj < len(grid[0]) and grid[ni][nj] != -1):
                            continue
                        total += grid[ni][nj]
                        cnt += 1
                        grid[ni][nj] = -1
                        new_q.append((ni, nj))
                q = new_q
            return total, cnt
    
        groups = [bfs(i, j) for i in xrange(len(grid)) for j in xrange(len(grid[0])) if grid[i][j] != -1]
        total = sum(t for t, _ in groups)
        return sum((total-t)*c for t, c in groups)
