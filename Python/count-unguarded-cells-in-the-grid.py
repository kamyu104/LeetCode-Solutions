# Time:  O(m * n)
# Space: O(m * n)

import itertools


# array, simulation
class Solution(object):
    def countUnguarded(self, m, n, guards, walls):
        """
        :type m: int
        :type n: int
        :type guards: List[List[int]]
        :type walls: List[List[int]]
        :rtype: int
        """
        DIRECTIONS = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        GREEN, RED, BLOCK = range(3)
        grid = [[GREEN]*n for _ in xrange(m)]
        for r, c in itertools.chain(guards, walls):
            grid[r][c] = BLOCK
        for r, c in guards:
            for dr, dc in DIRECTIONS:
                nr, nc = r+dr, c+dc
                while 0 <= nr < m and 0 <= nc < n and grid[nr][nc] != BLOCK:
                    grid[nr][nc] = RED
                    nr, nc = nr+dr, nc+dc
        return sum(grid[r][c] == GREEN for r in xrange(m) for c in xrange(n))
