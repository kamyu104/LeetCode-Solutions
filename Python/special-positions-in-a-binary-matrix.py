# Time:  O(n^2)
# Space: O(n)

class Solution(object):
    def numSpecial(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        rows, cols = [0]*len(mat), [0]*len(mat[0])
        for i in xrange(len(rows)):
            for j in xrange(len(cols)):
                if mat[i][j]:
                    rows[i] += 1
                    cols[j] += 1
        result = 0
        for i in xrange(len(rows)):
            for j in xrange(len(cols)):
                if mat[i][j] == rows[i] == cols[j] == 1:
                    result += 1
        return result
