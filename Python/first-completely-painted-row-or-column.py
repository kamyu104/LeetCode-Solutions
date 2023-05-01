# Time:  O(m * n)
# Space: O(m * n)

# hash table
class Solution(object):
    def firstCompleteIndex(self, arr, mat):
        """
        :type arr: List[int]
        :type mat: List[List[int]]
        :rtype: int
        """
        lookup = {mat[i][j]: (i, j) for i in xrange(len(mat)) for j in xrange(len(mat[0]))}
        row = [0]*len(mat)
        col = [0]*len(mat[0])
        for idx, x in enumerate(arr):
            i, j = lookup[x]
            row[i] += 1
            col[j] += 1
            if row[i] == len(mat[0]) or col[j] == len(mat):
                return idx
        return -1
