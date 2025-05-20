# Time:  O(m * n)
# Space: O(m * n)

import collections


# 0-1 bfs
class Solution(object):
    def minMoves(self, matrix):
        """
        :type matrix: List[str]
        :rtype: int
        """
        DIRECTIONS = [(0, -1), (0, 1), (-1, 0), (1, 0)]
        m, n = len(matrix), len(matrix[0])
        lookup = [[] for _ in xrange(26)]
        for i in xrange(m):
            for j in xrange(n):
                if matrix[i][j] in ".#":
                    continue
                lookup[ord(matrix[i][j])-ord('A')].append((i, j))
        lookup2 = [[False]*len(matrix[0]) for _ in xrange(m)]
        dq = collections.deque([(0, 0, 0)])
        while dq:
            step, i, j = dq.popleft()
            if lookup2[i][j]:
                continue
            lookup2[i][j] = True
            if (i, j) == (m-1, n-1):
                return step
            for di, dj in DIRECTIONS:
                ni, nj = i+di, j+dj
                if not (0 <= ni < m and 0 <= nj < n and matrix[ni][nj] != '#' and not lookup2[ni][nj]):
                    continue
                dq.append((step+1, ni, nj))
            if matrix[i][j] == '.':
                continue
            for ni, nj in lookup[ord(matrix[i][j])-ord('A')]:
                if lookup2[ni][nj]:
                    continue
                dq.appendleft((step, ni, nj))
            lookup[ord(matrix[i][j])-ord('A')] = []
        return -1
