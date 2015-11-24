# Time:  ctor:   O(mlogm * nlogn)
#        update: O(logm * logn)
#        query:  O(logm * logn)
# Space: O(m * n)

# Binary Indexed Tree (BIT) solution.
class NumMatrix(object):
    def __init__(self, matrix):
        """
        initialize your data structure here.
        :type matrix: List[List[int]]
        """
        if not matrix:
            return
        self.__matrix = matrix
        self.__m = len(matrix)
        self.__n = len(matrix[0])
        self.__bit = [[0] * (self.__n + 1) for _ in xrange(self.__m + 1)]
        for i in xrange(self.__m):
            for j in xrange(self.__n):
                self.__add(i, j, matrix[i][j])

    def update(self, row, col, val):
        """
        update the element at matrix[row,col] to val.
        :type row: int
        :type col: int
        :type val: int
        :rtype: void
        """
        if val - self.__matrix[row][col]:
            self.__add(row, col, val - self.__matrix[row][col])
            self.__matrix[row][col] = val


    def sumRegion(self, row1, col1, row2, col2):
        """
        sum of elements matrix[(row1,col1)..(row2,col2)], inclusive.
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        def sumRegion_bit(row, col):
            row += 1
            col += 1
            ret = 0
            i = row
            while i > 0:
                j = col
                while j > 0:
                    ret += self.__bit[i][j]
                    j -= (j & -j)
                i -= (i & -i)
            return ret
    
        ret = sumRegion_bit(row2, col2)
        if row1 > 0 and col1 > 0:
            ret += sumRegion_bit(row1 - 1, col1 - 1)
        if col1 > 0:
            ret -= sumRegion_bit(row2, col1 - 1)
        if row1 > 0:
            ret -= sumRegion_bit(row1 - 1, col2)
        return ret

    def __add(self, row, col, val):
        row += 1
        col += 1
        i = row
        while i <= self.__m:
            j = col
            while j <= self.__n:
                self.__bit[i][j] += val
                j += (j & -j)
            i += (i & -i)


# Your NumMatrix object will be instantiated and called as such:
# numMatrix = NumMatrix(matrix)
# numMatrix.sumRegion(0, 1, 2, 3)
# numMatrix.update(1, 1, 10)
# numMatrix.sumRegion(1, 2, 3, 4)
