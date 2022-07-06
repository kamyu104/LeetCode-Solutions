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
        lookup = set()
        row = collections.defaultdict(int)
        col = collections.defaultdict(int)
        diag = collections.defaultdict(int)
        anti = collections.defaultdict(int)
        
        for r, c in lamps:
            if (r, c) in lookup:
                continue
            lookup.add((r, c))
            row[r] += 1
            col[c] += 1
            diag[r-c] += 1
            anti[r+c] += 1
        
        result = []
        for r, c in queries:
            if not (row[r] or col[c] or diag[r-c] or anti[r+c]):
                result.append(0)
                continue
            result.append(1)                
            for nr in xrange(max(r-1, 0), min(r+1, N-1)+1):
                for nc in xrange(max(c-1, 0), min(c+1, N-1)+1):
                    if (nr, nc) not in lookup:
                        continue
                    lookup.remove((nr, nc))
                    row[nr] -= 1
                    col[nc] -= 1
                    diag[nr-nc] -= 1
                    anti[nr+nc] -= 1
        return result
