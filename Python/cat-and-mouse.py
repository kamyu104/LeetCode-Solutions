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
        DRAW, MOUSE, CAT = range(3)
        def parents(m, c, t):
            if t == CAT:
                for nm in graph[m]:
                    yield nm, c, MOUSE^CAT^t
            else:
                for nc in graph[c]:
                    if nc != HOLE:
                        yield m, nc, MOUSE^CAT^t

        degree = {}
        ignore = set(graph[HOLE])
        for m in xrange(len(graph)):
            for c in xrange(len(graph)):
                degree[m, c, MOUSE] = len(graph[m])
                degree[m, c, CAT] = len(graph[c])-(c in ignore)
        color = collections.defaultdict(int)
        q = collections.deque()
        for i in xrange(len(graph)):
            if i == HOLE:
                continue
            color[HOLE, i, CAT] = MOUSE
            q.append((HOLE, i, CAT, MOUSE))
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
        return color[MOUSE_START, CAT_START, MOUSE]

    
# Time:  O(n^3)
# Space: O(n^2)
import collections


class Solution2(object):
    def catMouseGame(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        HOLE, MOUSE_START, CAT_START = range(3)
        DRAW, MOUSE, CAT = range(3)
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
        ignore = set(graph[HOLE])
        for m in xrange(len(graph)):
            for c in xrange(len(graph)):
                degree[m, c, MOUSE] = len(graph[m])
                degree[m, c, CAT] = len(graph[c])-(c in ignore)
        q1 = collections.deque()
        q2 = collections.deque()
        for i in xrange(len(graph)):
            if i == HOLE:
                continue
            color[HOLE, i, CAT] = MOUSE
            q1.append((HOLE, i, CAT))
            for t in [MOUSE, CAT]:
                color[i, i, t] = CAT
                q2.append((i, i, t))
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
        while q2:
            i, j, t = q2.popleft()
            for ni, nj, nt in parents(i, j, t):
                if color[ni, nj, nt] != DRAW:
                    continue
                if t == MOUSE:
                    color[ni, nj, nt] = CAT
                    q2.append((ni, nj, nt))
                    continue
                degree[ni, nj, nt] -= 1
                if not degree[ni, nj, nt]:
                    color[ni, nj, nt] = CAT
                    q2.append((ni, nj, nt))
        return color[MOUSE_START, CAT_START, MOUSE]
