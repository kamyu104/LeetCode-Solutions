# Time:  O(m * n)
# Space: O(m * n)

import collections


class Solution(object):
    def minCost(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        R, C = len(grid), len(grid[0])
        dq = collections.deque([(0, 0, 0)])
        lookup = {(0, 0): 0}
        while dq:
            d, r, c = dq.popleft()
            if r == R-1 and c == C-1:
                return d
            for nd, (dr, dc) in enumerate(directions, 1):
                nr, nc = r+dr, c+dc
                cost = 1-(nd == grid[r][c])
                if not (0 <= nr < R and 0 <= nc < C and
                        ((nr, nc) not in lookup or d+cost < lookup[nr, nc])):
                    continue
                lookup[nr, nc] = d+cost
                if cost:
                    dq.append((d+cost, nr, nc))
                else:
                    dq.appendleft((d, nr, nc))
        return -1  # never reach here
