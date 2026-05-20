# Time:  O(n * m * logn * logm)
# Space: O(n * m * logn * logm)

# 2d sparse table
class Solution(object):
    def countLocalMaximums(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        # RMQ - 2D Sparse Table
        # Time:  ctor:  O(N * M * logN * logM) * O(fn)
        #        query: O(fn)
        # Space: O(N * M * logN * logM)
        class SparseTable2D(object):
            def __init__(self, matrix, fn):
                self.fn = fn
                n = len(matrix)
                m = len(matrix[0])
                logn = n.bit_length()-1  # log2_floor(n)
                logm = m.bit_length()-1  # log2_floor(m)
                self.bit_length = [0]
                for i in xrange(max(logn, logm)+1):
                    self.bit_length.extend(i+1 for _ in xrange(min(1<<i, (max(n, m)+1)-len(self.bit_length))))
                self.st = [[[[0]*m for _ in xrange(n)] for _ in xrange(logm+1)] for _ in xrange(logn+1)]
                for r in xrange(n):
                    for c in xrange(m):
                        self.st[0][0][r][c] = matrix[r][c]
                for j in xrange(1, logm+1):
                    for r in xrange(n):
                        for c in xrange((m-(1<<j))+1):
                            self.st[0][j][r][c] = fn(self.st[0][j-1][r][c], self.st[0][j-1][r][c+(1<<(j-1))])
                for i in xrange(1, logn+1):
                    for j in xrange(logm+1):
                        for r in xrange((n-(1<<i))+1):
                            for c in xrange((m-(1<<j))+1):
                                self.st[i][j][r][c] = fn(self.st[i-1][j][r][c], self.st[i-1][j][r+(1<<(i-1))][c])

            def query(self, r1, c1, r2, c2):  # Time: O(fn)
                i = self.bit_length[r2-r1+1]-1  # log2_floor(r2-r1+1)
                j = self.bit_length[c2-c1+1]-1  # log2_floor(c2-c1+1)
                return self.fn(
                    self.fn(self.st[i][j][r1][c1], self.st[i][j][r1][c2-(1<<j)+1]),
                    self.fn(self.st[i][j][r2-(1<<i)+1][c1], self.st[i][j][r2-(1<<i)+1][c2-(1<<j)+1])
                )

        n, m = len(matrix), len(matrix[0])
        st = SparseTable2D(matrix, max)
        result = 0
        for r in xrange(n):
            row = matrix[r]
            for c in xrange(m):
                x = row[c]
                if x == 0:
                    continue
                r1, r2 = max(0, r-x), min(n-1, r+x)
                c1, c2 = max(0, c-x), min(m-1, c+x)
                tl = r-x >= 0 and c-x >= 0
                tr = r-x >= 0 and c+x <= m-1
                bl = r+x <= n-1 and c-x >= 0
                br = r+x <= n-1 and c+x <= m-1
                if max(st.query(r1, c1+(1 if tl or bl else 0), r2, c2-(1 if tr or br else 0)),
                       st.query(r1+(1 if tl or tr else 0), c1, r2-(1 if bl or br else 0), c2)) <= x:
                    result += 1
        return result
