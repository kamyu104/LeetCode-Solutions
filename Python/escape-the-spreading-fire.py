# Time:  O(m * n)
# Space: O(m * n)

import collections


# bfs
class Solution(object):
    def maximumMinutes(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        DIRECTIONS = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        GRASS, FIRE, WALL, PERSON = range(4)
        INF = 10**9
        def bfs(grid):
            time = collections.defaultdict(int)
            d = 0
            q = [(r, c, FIRE) for r in xrange(len(grid)) for c in xrange(len(grid[0])) if grid[r][c] == FIRE]
            q.append((0, 0, PERSON))
            while q:
                new_q = []
                for r, c, t in q:
                    for dr, dc in DIRECTIONS:
                        nr, nc = r+dr, c+dc
                        if not (0 <= nr < len(grid) and 0 <= nc < len(grid[0]) and
                                grid[nr][nc] != WALL and
                                ((t == FIRE and grid[nr][nc] != FIRE) or
                                 (t == PERSON and (grid[nr][nc] == GRASS or (grid[nr][nc] == FIRE and (nr, nc) == (len(grid)-1, len(grid[0])-1) and d+1 == time[FIRE, nr, nc]))))):
                            continue
                        if grid[nr][nc] != FIRE:
                            grid[nr][nc] = t
                        if (nr, nc) in ((len(grid)-1, len(grid[0])-1), (len(grid)-1, len(grid[0])-2), (len(grid)-2, len(grid[0])-1)):
                            time[t, nr, nc] = d+1
                        new_q.append((nr, nc, t))
                q = new_q
                d += 1
            return time

        time = bfs(grid)
        if not time[PERSON, len(grid)-1, len(grid[0])-1]:
            return -1
        if not time[FIRE, len(grid)-1, len(grid[0])-1]:
            return INF
        diff = time[FIRE, len(grid)-1, len(grid[0])-1]-time[PERSON, len(grid)-1, len(grid[0])-1]
        return diff if diff+2 in (time[FIRE, len(grid)-1, len(grid[0])-2]-time[PERSON, len(grid)-1, len(grid[0])-2],
                                  time[FIRE, len(grid)-2, len(grid[0])-1]-time[PERSON, len(grid)-2, len(grid[0])-1]) else diff-1


# Time:  O(m * n)
# Space: O(m * n)
# bfs
class Solution2(object):
    def maximumMinutes(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        DIRECTIONS = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        FIRE, WALL, PERSON = range(1, 4)
        INF = 10**9
        def bfs(grid):
            time = {FIRE:[[INF]*len(grid[0]) for _ in xrange(len(grid))],
                    PERSON:[[INF]*len(grid[0]) for _ in xrange(len(grid))]}
            d = 0
            q = [(r, c, FIRE) for r in xrange(len(grid)) for c in xrange(len(grid[0])) if grid[r][c] == FIRE]
            q.append((0, 0, PERSON))
            for r, c, t in q:
                time[t][r][c] = d
            while q:
                new_q = []
                for r, c, t in q:
                    for dr, dc in DIRECTIONS:
                        nr, nc = r+dr, c+dc
                        if not (0 <= nr < len(grid) and 0 <= nc < len(grid[0]) and
                                grid[nr][nc] != WALL and time[t][nr][nc] == INF and
                                (t == FIRE or
                                 d+1 < time[FIRE][nr][nc] or (d+1 == time[FIRE][nr][nc] and (nr, nc) == (len(grid)-1, len(grid[0])-1)))):
                            continue
                        time[t][nr][nc] = d+1
                        new_q.append((nr, nc, t))
                q = new_q
                d += 1
            return time

        time = bfs(grid)
        if time[PERSON][-1][-1] == INF:
            return -1
        if time[FIRE][-1][-1] == INF:
            return INF
        diff = time[FIRE][-1][-1]-time[PERSON][-1][-1]
        return diff if diff+2 in (time[FIRE][-1][-2]-time[PERSON][-1][-2], time[FIRE][-2][-1]-time[PERSON][-2][-1]) else diff-1
