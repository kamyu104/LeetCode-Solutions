# Time:  O(m * n)
# Space: O(m * n)

class Solution(object):
    def numEnclaves(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]
        def dfs(A, i, j):
            if not (0 <= i < len(A) and 0 <= j < len(A[0]) and A[i][j]):
                return
            A[i][j] = 0
            for d in directions:
                dfs(A, i+d[0], j+d[1])
        
        for i in xrange(len(A)):
            dfs(A, i, 0)
            dfs(A, i, len(A[0])-1)
        for j in xrange(1, len(A[0])-1):
            dfs(A, 0, j)
            dfs(A, len(A)-1, j)
        return sum(sum(row) for row in A)
  
