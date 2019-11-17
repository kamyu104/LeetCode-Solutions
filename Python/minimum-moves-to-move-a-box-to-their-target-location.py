# Time:  O(m^2 * n^2)
# Space: O(m^2 * n^2)

# a star algorithm without heap
class Solution(object):
    def minPushBox(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        def dot(p1, p2):
            return p1[0]*p2[0]+p1[1]*p2[1]

        def can_reach(b, p, t):
            closer, detour = [p], []
            lookup = set([b])
            while True:
                if not closer:
                    if not detour:
                        return False
                    closer, detour = detour, closer
                p = closer.pop()
                if p == t:
                    break
                if p in lookup:
                    continue
                lookup.add(p)
                for dx, dy in directions:
                    np = (p[0]+dx, p[1]+dy)
                    if not (0 <= np[0] < len(grid) and 0 <= np[1] < len(grid[0]) and
                       grid[np[0]][np[1]] != '#' and np not in lookup):
                        continue
                    (closer if dot((dx, dy), (t[0]-p[0], t[1]-p[1])) > 0 else detour).append(np)
            return True

        def g(p1, p2):
            return abs(p1[0]-p2[0])+abs(p1[1]-p2[1])
        
        def a_star(b, p, t):
            f, h = g(b, t), 2
            closer, detour = [(b, p)], []
            lookup = set()
            while True:
                if not closer:
                    if not detour:
                        return -1
                    f += h
                    closer, detour = detour, closer
                b, p = closer.pop()
                if b == t:
                    break
                if b in lookup:
                    continue
                lookup.add((b, p))
                for dx, dy in directions:
                    nb, np = (b[0]+dx, b[1]+dy), (b[0]-dx, b[1]-dy)
                    if not (0 <= nb[0] < len(grid) and 0 <= nb[1] < len(grid[0]) and
                            0 <= np[0] < len(grid) and  0 <= np[1] < len(grid[0]) and
                            grid[nb[0]][nb[1]] != '#' and grid[np[0]][np[1]] != '#' and
                            (nb, b) not in lookup and can_reach(b, p, np)):
                        continue
                    (closer if dot((dx, dy), (t[0]-b[0], t[1]-b[1])) > 0 else detour).append((nb, b))
            return f
        
        b, p, t = None, None, None
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if grid[i][j] == 'B':
                    b = (i, j)
                elif grid[i][j] == 'S':
                    p = (i, j)
                elif grid[i][j] == 'T':
                    t = (i, j)
        return a_star(b, p, t)
