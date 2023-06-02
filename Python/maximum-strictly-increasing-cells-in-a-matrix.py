# Time:  O(m * n * log(m * n))
# Space: O(m * n)

import collections


# sort, dp
class Solution(object):
    def maxIncreasingCells(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        lookup = collections.defaultdict(list)
        for i in xrange(len(mat)):
            for j in xrange(len(mat[0])):
                lookup[mat[i][j]].append((i, j))
        dp = [[0]*len(mat[0]) for _ in xrange(len(mat))]
        row, col = [0]*len(mat), [0]*len(mat[0])
        for x in sorted(lookup.iterkeys()):
            for i, j in lookup[x]:
                dp[i][j] = max(row[i], col[j])+1
            for i, j in lookup[x]:
                row[i] = max(row[i], dp[i][j])
                col[j] = max(col[j], dp[i][j])
        return max(row)
