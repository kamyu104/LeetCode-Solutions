# Time:  O(m * n)
# Space: O(1)

# constructive algorithms
PATTERNS = [
    [],
    [["."]], 
    [["..", ".."]],
    [["..", "..", ".."], ["...", "..."]],
    [["..", "..", "..", ".."], ["....", "...."], ["..#", "...", "#.."]],
]
class Solution(object):
    def createGrid(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: List[str]
        """
        for p in PATTERNS[k]:
            if not (len(p) <= m and len(p[0]) <= n):
                continue
            result = [['#']*n for _ in xrange(m)]
            for i in xrange(len(p)):
                for j in xrange(len(p[0])):
                    result[i][j] = p[i][j]
            for i in xrange(len(p), m):
                result[i][len(p[0])-1] = '.'
            for j in xrange(len(p[0]), n):
                result[m-1][j] = '.'
            return ["".join(row) for row in result]
        return []
