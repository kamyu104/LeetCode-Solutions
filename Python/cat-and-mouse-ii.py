# Time:  O((m * n)^2 * (m + n))
# Space: O((m * n)^2)
class Solution(object):
    def canMouseWin(self, grid, catJump, mouseJump):
        """
        :type grid: List[str]
        :type catJump: int
        :type mouseJump: int
        :rtype: bool
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        DRAW, MOUSE, CAT = 0, 1, 2
        R, C = len(grid), len(grid[0])
        N = R*C
        WALLS = set()
        FOOD, MOUSE_START, CAT_START = [-1]*3
        for i in xrange(R):
            for j in xrange(C):
                if grid[i][j] == 'M':
                    MOUSE_START = i*C + j
                elif grid[i][j] == 'C':
                    CAT_START = i*C + j
                elif grid[i][j] == 'F':
                    FOOD = i*C + j
                elif grid[i][j] == '#':
                    WALLS.add(i*C + j)
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
                degree[m, c, CAT] = len(graph[c, CAT])
                # degree[m, c, MOUSE] = len(graph[m, MOUSE])
        color = collections.defaultdict(int)
        q1 = collections.deque()
        # q2 = collections.deque()
        for i in xrange(len(graph)):
            if i in WALLS or i == FOOD:
                continue
            color[FOOD, i, CAT] = MOUSE
            q1.append((FOOD, i, CAT))
            # for t in [MOUSE, CAT]:
            #     color[i, i, t] = CAT
            #     q2.append((i, i, t))
        while q1:
            i, j, t = q1.popleft()
            if t == CAT:
                for ni in graph[i, MOUSE]:
                    if ni != FOOD and j != FOOD and ni != j and color[ni, j, MOUSE] == DRAW:
                        color[ni, j, MOUSE] = MOUSE
                        q1.append((ni, j, MOUSE))
            else:
                for nj in graph[j, CAT]:
                    if i != FOOD and nj != FOOD and i != nj and color[i, nj, CAT] == DRAW:
                        degree[i, nj, CAT] -= 1
                        if not degree[i, nj, CAT]:
                            color[i, nj, CAT] = MOUSE
                            q1.append((i, nj, CAT))
        # while q2:
        #     i, j, t = q2.popleft()
        #     if t == MOUSE:
        #         for nj in graph[j, CAT]:
        #             if i != FOOD and nj != FOOD and i != nj and color[i, nj, CAT] == DRAW:
        #                 color[i, nj, CAT] = CAT
        #                 q2.append((i, nj, CAT))
        #     else:
        #         for ni in graph[i, MOUSE]:
        #             if ni != FOOD and j != FOOD and ni != j and color[ni, j, MOUSE] == DRAW:
        #                 degree[ni, j, MOUSE] -= 1
        #                 if not degree[ni, j, MOUSE]:
        #                     color[ni, j, MOUSE] = CAT
        #                     q2.append((ni, j, MOUSE))
        return color[MOUSE_START, CAT_START, MOUSE] == MOUSE
