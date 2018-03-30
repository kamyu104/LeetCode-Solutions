# Time:  O(n!)
# Space: O(n)

# The n-queens puzzle is the problem of placing n queens on 
# an nxn chess board such that no two queens attack each other.
# 
# Given an integer n, return all distinct solutions to the n-queens puzzle.
# 
# Each solution contains a distinct board configuration of the n-queens' placement, 
# where 'Q' and '.' both indicate a queen and an empty space respectively.
# 
# For example,
# There exist two distinct solutions to the 4-queens puzzle:
# 
# [
#  [".Q..",  // Solution 1
#   "...Q",
#   "Q...",
#   "..Q."],
# 
#  ["..Q.",  // Solution 2
#   "Q...",
#   "...Q",
#   ".Q.."]
# ]

class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        def dfs(curr, cols, main_diag, anti_diag, result):
            row, n = len(curr), len(cols)
            if row == n:
                result.append(map(lambda x: '.'*x + "Q" + '.'*(n-x-1), curr))
                return
            for i in xrange(n):
                if cols[i] or main_diag[row+i] or anti_diag[row-i+n]:
                    continue
                cols[i] = main_diag[row+i] = anti_diag[row-i+n] = True
                curr.append(i)
                dfs(curr, cols, main_diag, anti_diag, result)
                curr.pop()
                cols[i] = main_diag[row+i] = anti_diag[row-i+n] = False
                
        result = []
        cols, main_diag, anti_diag = [False]*n, [False]*(2*n), [False]*(2*n)
        dfs([], cols, main_diag, anti_diag, result)
        return result

                    
# For any point (x,y), if we want the new point (p,q) don't share the same row, column, or diagonal.
# then there must have ```p+q != x+y``` and ```p-q!= x-y``` 
# the former focus on eliminate 'left bottom right top' diagonal; 
# the latter focus on eliminate 'left top right bottom' diagonal

# - col_per_row: the list of column index per row
# - cur_row：current row we are seraching for valid column
# - xy_diff：the list of x-y
# - xy_sum：the list of x+y   
class Solution2(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        def dfs(col_per_row, xy_diff, xy_sum):
            cur_row = len(col_per_row)
            if cur_row == n:
                ress.append(col_per_row)
            for col in range(n):
                if col not in col_per_row and cur_row-col not in xy_diff and cur_row+col not in xy_sum:
                    dfs(col_per_row+[col], xy_diff+[cur_row-col], xy_sum+[cur_row+col])
        ress = []
        dfs([], [], [])
        return [['.'*i + 'Q' + '.'*(n-i-1) for i in res] for res in ress]
               
                    
if __name__ == "__main__":
    print Solution().solveNQueens(8)
