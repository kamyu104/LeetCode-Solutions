# Time:  O(m * n)
# Space: O(1)

class Solution(object):
    def findRotation(self, mat, target):
        """
        :type mat: List[List[int]]
        :type target: List[List[int]]
        :rtype: bool
        """
        checks = [lambda i, j: mat[i][j] == target[i][j],
                  lambda i, j: mat[i][j] == target[j][-1-i],
                  lambda i, j: mat[i][j] == target[-1-i][-1-j],
                  lambda i, j: mat[i][j] == target[-1-j][i]]
        traverse = lambda check: all(check(i, j) for i in xrange(len(mat)) for j in xrange(len(mat[0])))
        return any(traverse(check) for check in checks)
