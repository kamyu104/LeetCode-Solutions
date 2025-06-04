# Time:  O(m * n * 2^l)
# Space: O(m * n * 2^l)

# bfs, bitmasks
class Solution(object):
    def minMoves(self, classroom, energy):
        """
        :type classroom: List[str]
        :type energy: int
        :rtype: int
        """
        DIRECTIONS = ((1, 0), (0, 1), (-1, 0), (0, -1))
        m, n = len(classroom), len(classroom[0])
        lookup = {}
        r = c = -1
        for i in xrange(m):
            for j in xrange(len(classroom[i])):
                curr = classroom[i][j]
                if curr == 'S':
                    r, c = i, j
                elif curr == 'L':
                    lookup[(i, j)] = len(lookup)
        lookup2 = [[[-1]*(1<<len(lookup)) for _ in xrange(n)] for _ in xrange(m)]
        lookup2[r][c][0] = energy
        q = [(r, c, 0, energy)]
        result = 0
        while q:
            new_q = []
            for i, j, mask, e in q:
                if lookup2[i][j][mask] != e:
                    continue
                if mask == (1<<len(lookup))-1:
                    return result
                for di, dj in DIRECTIONS:
                    ni, nj = i+di, j+dj
                    ne = e-1
                    if not (0 <= ni < m and 0 <= nj < n and classroom[ni][nj] != 'X' and ne >= 0):
                        continue
                    new_mask = mask
                    if classroom[ni][nj] == 'R':
                        ne = energy
                    elif classroom[ni][nj] == 'L':
                        new_mask |= 1<<lookup[(ni, nj)]
                    if ne <= lookup2[ni][nj][new_mask]:
                        continue
                    lookup2[ni][nj][new_mask] = ne
                    new_q.append((ni, nj, new_mask, ne))
            q = new_q
            result += 1
        return -1
