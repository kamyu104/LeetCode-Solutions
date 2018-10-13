from functools import reduce
# Time:  O(n!)
# Space: O(n)

class Solution(object):
    # @return an integer
    def totalNQueens(self, n):
        self.cols = [False] * n
        self.main_diag = [False] * (2 * n)
        self.anti_diag = [False] * (2 * n)
        return self.totalNQueensRecu([], 0, n)

    def totalNQueensRecu(self, solution, row, n):
        if row == n:
            return 1
        result = 0
        for i in xrange(n):
            if not self.cols[i] and not self.main_diag[row + i] and not self.anti_diag[row - i + n]:
                self.cols[i] = self.main_diag[row + i] = self.anti_diag[row - i + n] = True
                result += self.totalNQueensRecu(solution + [i], row + 1, n)
                self.cols[i] = self.main_diag[row + i] = self.anti_diag[row - i + n] = False
        return result

# slower solution
class Solution2(object):
    # @return an integer
    def totalNQueens(self, n):
        return self.totalNQueensRecu([], 0, n)

    def totalNQueensRecu(self, solution, row, n):
        if row == n:
            return 1
        result = 0
        for i in xrange(n):
            if i not in solution and reduce(lambda acc, j: abs(row - j) != abs(i - solution[j]) and acc, xrange(len(solution)), True):
                result += self.totalNQueensRecu(solution + [i], row + 1, n)
        return result

