# Time:  O(m * n)
# Space: O(m * n)

# A* Search Algorithm without heap
class Solution(object):
    def minimumObstacles(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        def a_star(grid, b, t):
            f, dh = 0, 1
            closer, detour = [b], []
            lookup = [[False]*len(grid[0]) for _ in xrange(len(grid))]
            while closer or detour:
                if not closer:
                    f += dh
                    closer, detour = detour, closer
                b = closer.pop()
                if b == t:
                    return f
                if lookup[b[0]][b[1]]:
                    continue
                lookup[b[0]][b[1]] = True
                for dr, dc in directions:
                    nb = (b[0]+dr, b[1]+dc)
                    if not (0 <= nb[0] < len(grid) and 0 <= nb[1] < len(grid[0]) and not lookup[nb[0]][nb[1]]):
                        continue
                    (closer if not grid[b[0]][b[1]] else detour).append(nb)
            return -1

        return a_star(grid, (0, 0), (len(grid)-1, len(grid[0])-1))


# Time:  O(m * n)
# Space: O(m * n)
import collections


# 0-1 bfs solution
class Solution2(object):
    def minimumObstacles(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        b, t = (0, 0), (len(grid)-1, len(grid[0])-1)
        dq = collections.deque([(b, 0)])
        lookup = [[False]*len(grid[0]) for _ in xrange(len(grid))]
        while dq:
            b, d = dq.popleft()
            if b == t:
                return d
            if lookup[b[0]][b[1]]:
                continue
            lookup[b[0]][b[1]] = True
            for dr, dc in directions:
                nb = (b[0]+dr, b[1]+dc)
                if not (0 <= nb[0] < len(grid) and 0 <= nb[1] < len(grid[0]) and not lookup[nb[0]][nb[1]]):
                    continue
                if not grid[b[0]][b[1]]:
                    dq.appendleft((nb, d))
                else:
                    dq.append((nb, d+1))
        return -1  # never reach here
