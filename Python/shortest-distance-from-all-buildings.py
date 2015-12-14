# Time:  O(k * m * n), k is the number of the buildings
# Space: O(m * n)

class Solution(object):
    def shortestDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def bfs(grid, dists, reachable, x, y):
            dist, m, n = 0, len(grid), len(grid[0])
            visited = [[False for _ in xrange(n)] for _ in xrange(m)]
    
            pre_level = [(x, y)]
            visited[x][y] = True  # enqueue, then visited
            while pre_level:
                cur_level = []
                for i, j in pre_level:
                    dists[i][j] += dist
    
                    for dir in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                        I, J = i+dir[0], j+dir[1]
                        if 0 <= I < m and 0 <= J < n and grid[I][J] == 0 and not visited[I][J]:
                            cur_level.append((I, J))
                            visited[I][J] = True
    
                dist += 1
                pre_level = cur_level
    
            for i in xrange(m):
                for j in xrange(n):
                    if not visited[i][j]:
                        reachable[i][j] = False

        m, n = len(grid),  len(grid[0])
        dists = [[0 for _ in xrange(n)] for _ in xrange(m)]
        reachable = [[True for _ in xrange(n)] for _ in xrange(m)]
        for i in xrange(m):
            for j in xrange(n):
                if grid[i][j] > 0:
                    reachable[i][j] = False
                    dists[i][j] = float("inf")

        for i in xrange(m):
            for j in xrange(n):
                if grid[i][j] == 1:
                    bfs(grid, dists, reachable, i, j)

        shortest = float("inf")
        for i in xrange(m):
            for j in xrange(n):
                if dists[i][j] < shortest and reachable[i][j]:
                    shortest = dists[i][j]

        return shortest if shortest != float("inf") else -1
