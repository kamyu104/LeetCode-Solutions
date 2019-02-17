# Time:  O(m * n)
# Space: O(m * n)

import collections


class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        count = 0
        q = collections.deque()
        for r, row in enumerate(grid):
            for c, val in enumerate(row):
                if val == 2:
                    q.append((r, c, 0))
                elif val == 1:
                    count += 1

        result = 0
        while q:
            r, c, result = q.popleft()
            for d in directions:
                nr, nc = r+d[0], c+d[1]
                if not (0 <= nr < len(grid) and \
                        0 <= nc < len(grid[r])):
                    continue
                if grid[nr][nc] == 1:
                    count -= 1
                    grid[nr][nc] = 2
                    q.append((nr, nc, result+1))
        return result if count == 0 else -1
