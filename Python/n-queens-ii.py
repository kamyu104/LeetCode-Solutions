# Time:  O(n!)
# Space: O(n)

class Solution(object):
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        def dfs(row):
            if row == n:
                return 1
            result = 0
            for i in xrange(n):
                if cols[i] or main_diag[row+i] or anti_diag[row-i+(n-1)]:
                    continue
                cols[i] = main_diag[row+i] = anti_diag[row-i+(n-1)] = True
                result += dfs(row+1)
                cols[i] = main_diag[row+i] = anti_diag[row-i+(n-1)] = False
            return result

        result = []
        cols, main_diag, anti_diag = [False]*n, [False]*(2*n-1), [False]*(2*n-1)
        return dfs(0)

