# Time:  O(m * n)
# Space: O(m * n)

# simulation, bfs
class Solution(object):
    def minimumSeconds(self, land):
        """
        :type land: List[List[str]]
        :rtype: int
        """
        DIRECTIONS = ((1, 0), (0, 1), (-1, 0), (0, -1))
        lookup = [[0 if land[i][j] != "*" else -1 for j in xrange(len(land[0]))] for i in xrange(len(land))]
        q = [(i, j, -1) for i in xrange(len(land)) for j in xrange(len(land[0])) if land[i][j] == "*"]
        q.append(next((i, j, 0) for i in xrange(len(land)) for j in xrange(len(land[0])) if land[i][j] == "S"))
        while q:
            new_q = []
            for i, j, d in q:
                if land[i][j] == "D":
                    return d
                for di, dj in DIRECTIONS:
                    ni, nj = i+di, j+dj
                    if not (0 <= ni < len(land) and 0 <= nj < len(land[0]) and land[ni][nj] != "X" and lookup[ni][nj] != -1):
                        continue
                    if d != -1 and lookup[ni][nj] == 0:
                        lookup[ni][nj] = 1
                        new_q.append((ni, nj, d+1))
                    elif d == -1 and land[ni][nj] != "D":
                        lookup[ni][nj] = -1
                        new_q.append((ni, nj, -1))
            q = new_q
        return -1


# Time:  O(m * n)
# Space: O(m * n)
# simulation, bfs
class Solution2(object):
    def minimumSeconds(self, land):
        """
        :type land: List[List[str]]
        :rtype: int
        """
        DIRECTIONS = ((1, 0), (0, 1), (-1, 0), (0, -1))
        lookup = [[0 if land[i][j] != "*" else -1 for j in xrange(len(land[0]))] for i in xrange(len(land))]
        q1 = [(i, j) for i in xrange(len(land)) for j in xrange(len(land[0])) if land[i][j] == "*"]
        q2 = [next((i, j, 0) for i in xrange(len(land)) for j in xrange(len(land[0])) if land[i][j] == "S")]
        while q1 or q2:
            new_q1, new_q2 = [], []
            for i, j in q1:
                for di, dj in DIRECTIONS:
                    ni, nj = i+di, j+dj
                    if not (0 <= ni < len(land) and 0 <= nj < len(land[0]) and land[ni][nj] != "X" and land[ni][nj] != "D" and lookup[ni][nj] != -1):
                        continue
                    lookup[ni][nj] = -1
                    new_q1.append((ni, nj))
            for i, j, d in q2:
                if land[i][j] == "D":
                    return d
                for di, dj in DIRECTIONS:
                    ni, nj = i+di, j+dj
                    if not (0 <= ni < len(land) and 0 <= nj < len(land[0]) and land[ni][nj] != "X" and lookup[ni][nj] == 0):
                        continue
                    lookup[ni][nj] = 1
                    new_q2.append((ni, nj, d+1))
            q1, q2 = new_q1, new_q2
        return -1
