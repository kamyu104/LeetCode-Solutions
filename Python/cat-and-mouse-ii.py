# Time:  O((m * n)^2 * (m + n))
# Space: O((m * n)^2)

import collections


class Solution(object):
    def canMouseWin(self, grid, catJump, mouseJump):
        """
        :type grid: List[str]
        :type catJump: int
        :type mouseJump: int
        :rtype: bool
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        DRAW, MOUSE, CAT = range(3)
        def parents(m, c, t):
            if t == CAT:
                for nm in graph[m, MOUSE^CAT^t]:
                    yield nm, c, MOUSE^CAT^t
            else:
                for nc in graph[c, MOUSE^CAT^t]:
                    yield m, nc, MOUSE^CAT^t

        R, C = len(grid), len(grid[0])
        N = R*C
        WALLS = set()
        FOOD, MOUSE_START, CAT_START = [-1]*3
        for r in xrange(R):
            for c in xrange(C):
                if grid[r][c] == 'M':
                    MOUSE_START = r*C + c
                elif grid[r][c] == 'C':
                    CAT_START = r*C + c
                elif grid[r][c] == 'F':
                    FOOD = r*C + c
                elif grid[r][c] == '#':
                    WALLS.add(r*C + c)

        graph = collections.defaultdict(set)
        jump = {MOUSE:mouseJump, CAT:catJump}
        for r in xrange(R):
            for c in xrange(C):
                if grid[r][c] == '#':
                    continue
                pos = r*C + c
                for t in [MOUSE, CAT]:
                    for dr, dc in directions:
                        for d in xrange(jump[t]+1):
                            nr, nc = r+dr*d, c+dc*d
                            if not (0 <= nr < R and 0 <= nc < C and grid[nr][nc] != '#'):
                                break
                            graph[pos, t].add(nr*C + nc)

        degree = {}
        for m in xrange(N):
            for c in xrange(N):
                degree[m, c, MOUSE] = len(graph[m, MOUSE])
                degree[m, c, CAT] = len(graph[c, CAT])
        color = collections.defaultdict(int)
        q = collections.deque()
        for i in xrange(N):
            if i in WALLS or i == FOOD:
                continue
            color[FOOD, i, CAT] = MOUSE
            q.append((FOOD, i, CAT, MOUSE))
            color[i, FOOD, MOUSE] = CAT
            q.append((i, FOOD, MOUSE, CAT))
            for t in [MOUSE, CAT]:
                color[i, i, t] = CAT
                q.append((i, i, t, CAT))
        while q:
            i, j, t, c = q.popleft()
            for ni, nj, nt in parents(i, j, t):
                if color[ni, nj, nt] != DRAW:
                    continue
                if nt == c:
                    color[ni, nj, nt] = c
                    q.append((ni, nj, nt, c))
                    continue
                degree[ni, nj, nt] -= 1
                if not degree[ni, nj, nt]:
                    color[ni, nj, nt] = c
                    q.append((ni, nj, nt, c))
        return color[MOUSE_START, CAT_START, MOUSE] == MOUSE


# Time:  O((m * n)^2 * (m + n))
# Space: O((m * n)^2)
import collections


class Solution2(object):
    def canMouseWin(self, grid, catJump, mouseJump):
        """
        :type grid: List[str]
        :type catJump: int
        :type mouseJump: int
        :rtype: bool
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        DRAW, MOUSE, CAT = range(3)
        def parents(m, c, t):
            if t == CAT:
                for nm in graph[m, MOUSE^CAT^t]:
                    yield nm, c, MOUSE^CAT^t
            else:
                for nc in graph[c, MOUSE^CAT^t]:
                    yield m, nc, MOUSE^CAT^t

        R, C = len(grid), len(grid[0])
        N = R*C
        WALLS = set()
        FOOD, MOUSE_START, CAT_START = [-1]*3
        for r in xrange(R):
            for c in xrange(C):
                if grid[r][c] == 'M':
                    MOUSE_START = r*C + c
                elif grid[r][c] == 'C':
                    CAT_START = r*C + c
                elif grid[r][c] == 'F':
                    FOOD = r*C + c
                elif grid[r][c] == '#':
                    WALLS.add(r*C + c)
        graph = collections.defaultdict(set)
        jump = {MOUSE:mouseJump, CAT:catJump}
        for r in xrange(R):
            for c in xrange(C):
                if grid[r][c] == '#':
                    continue
                pos = r*C + c
                for t in [MOUSE, CAT]:
                    for dr, dc in directions:
                        for d in xrange(jump[t]+1):
                            nr, nc = r+dr*d, c+dc*d
                            if not (0 <= nr < R and 0 <= nc < C and grid[nr][nc] != '#'):
                                break
                            graph[pos, t].add(nr*C + nc)

        degree = {}
        for m in xrange(N):
            for c in xrange(N):
                # degree[m, c, MOUSE] = len(graph[m, MOUSE])
                degree[m, c, CAT] = len(graph[c, CAT])
        color = collections.defaultdict(int)
        q1 = collections.deque()
        # q2 = collections.deque()
        for i in xrange(N):
            if i in WALLS or i == FOOD:
                continue
            color[FOOD, i, CAT] = MOUSE
            q1.append((FOOD, i, CAT))
            color[i, FOOD, MOUSE] = CAT
            # q2.append((i, FOOD, MOUSE))
            for t in [MOUSE, CAT]:
                color[i, i, t] = CAT
                # q2.append((i, i, t))
        while q1:
            i, j, t = q1.popleft()
            for ni, nj, nt in parents(i, j, t):
                if color[ni, nj, nt] != DRAW:
                    continue
                if t == CAT:
                    color[ni, nj, nt] = MOUSE
                    q1.append((ni, nj, nt))
                    continue
                degree[ni, nj, nt] -= 1
                if not degree[ni, nj, nt]:
                    color[ni, nj, nt] = MOUSE
                    q1.append((ni, nj, nt))
        # while q2:
        #     i, j, t = q2.popleft()
        #     for ni, nj, nt in parents(i, j, t):
        #         if color[ni, nj, nt] != DRAW:
        #             continue
        #         if t == MOUSE:
        #             color[ni, nj, nt] = CAT
        #             q2.append((ni, nj, nt))
        #             continue
        #         degree[ni, nj, nt] -= 1
        #         if not degree[ni, nj, nt]:
        #             color[ni, nj, nt] = CAT
        #             q2.append((ni, nj, nt))
        return color[MOUSE_START, CAT_START, MOUSE] == MOUSE
