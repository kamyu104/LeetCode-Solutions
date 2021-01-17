# Time:  O(n^3)
# Space: O(n^2)

import collections


class Solution(object):
    def catMouseGame(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        HOLE, MOUSE_START, CAT_START = range(3)
        DRAW, MOUSE, CAT = 0, 1, 2
        def parents(m, c, t):
            if t == CAT:
                for nm in graph[m]:
                    yield nm, c, MOUSE^CAT^t
            else:
                for nc in graph[c]:
                    if nc != HOLE:
                        yield m, nc, MOUSE^CAT^t

        color = collections.defaultdict(int)
        degree = {}
        for m in xrange(len(graph)):
            for c in xrange(len(graph)):
                degree[m, c, MOUSE] = len(graph[m])
                degree[m, c, CAT] = len(graph[c])-(0 in graph[c])
        q = collections.deque()
        for i in xrange(len(graph)):
            for t in [MOUSE, CAT]:
                color[HOLE, i, t] = MOUSE
                q.append((0, i, t, MOUSE))
                if i > 0:
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
                    color[ni, nj, nt] = MOUSE^CAT^nt
                    q.append((ni, nj, nt, MOUSE^CAT^nt))
        return color[MOUSE_START, CAT_START, MOUSE]

