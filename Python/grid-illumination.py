# Time:  O(l + q)
# Space: O(l)

import collections


class Solution(object):
    def gridIllumination(self, N, lamps, queries):
        """
        :type N: int
        :type lamps: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0),
                      (-1, -1), (1, -1), (1, -1), (1, 1)]

        lookup = set()
        row = collections.defaultdict(int)
        col = collections.defaultdict(int)
        diag = collections.defaultdict(int)
        anti = collections.defaultdict(int)
        
        for r, c in lamps:
            lookup.add((r, c))
            row[r] += 1
            col[c] += 1
            diag[r-c] += 1
            anti[r+c] += 1
        
        result = []
        for r, c in queries:
            if row[r] or col[c] or \
               diag[r-c] or anti[r+c]:
                result.append(1)
            else:
                result.append(0)
            for d in directions:
                nc, nr = r+d[0], c+d[1]
                if not (0 <= nr < N and 0 <= nc < N and \
                        (nr, nc) in lookup):
                    continue
                lookup.remove((nr, nc))
                row[nr] -= 1
                col[nc] -= 1
                diag[nr-nc] -= 1
                anti[nr+nc] -= 1
        return result
