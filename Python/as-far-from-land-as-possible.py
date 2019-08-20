# Time:  O(m * n)
# Space: O(m * n)

import collections


class Solution(object):
    def maxDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        q = collections.deque([(i, j) for i in xrange(len(grid))
                                      for j in xrange(len(grid[0])) if grid[i][j] == 1])    
        if len(q) == len(grid)*len(grid[0]):
            return -1
        level = -1
        while q:
            next_q = collections.deque()
            while q:
                x, y = q.popleft()
                for dx, dy in directions:
                    nx, ny = x+dx, y+dy
                    if not (0 <= nx < len(grid) and 
                            0 <= ny < len(grid[0]) and 
                            grid[nx][ny] == 0):
                        continue
                    next_q.append((nx, ny))
                    grid[nx][ny] = 1
            q = next_q
            level += 1
        return level
