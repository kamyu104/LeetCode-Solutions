# Time:  O(m * n)
# Space: O(m * n)

import collections


# 0-1 bfs, deque
class Solution(object):
    def findSafeWalk(self, grid, health):
        """
        :type grid: List[List[int]]
        :type health: int
        :rtype: bool
        """
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        b, t = (0, 0), (len(grid)-1, len(grid[0])-1)
        if not 0+grid[0][0] < health:
            return False
        dq = collections.deque([(b, grid[0][0])])
        lookup = set()
        while dq:
            b, d = dq.popleft()
            if b in lookup:
                continue
            lookup.add(b)
            if b == t:
                return True
            for dr, dc in directions:
                nb = (b[0]+dr, b[1]+dc)
                if not (0 <= nb[0] < len(grid) and 0 <= nb[1] < len(grid[0]) and nb not in lookup):
                    continue
                if not grid[nb[0]][nb[1]]:
                    dq.appendleft((nb, d))
                elif d+1 < health:
                    dq.append((nb, d+1))
        return False
