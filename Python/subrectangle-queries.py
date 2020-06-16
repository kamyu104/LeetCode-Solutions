# Time:  ctor:   O(1)
#        update: O(1)
#        get:    O(u), u is the number of updates
# Space: O(u)

class SubrectangleQueries(object):

    def __init__(self, rectangle):
        """
        :type rectangle: List[List[int]]
        """
        self.__rectangle = rectangle
        self.__updates = []
        

    def updateSubrectangle(self, row1, col1, row2, col2, newValue):
        """
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :type newValue: int
        :rtype: None
        """
        self.__updates.append((row1, col1, row2, col2, newValue))

    def getValue(self, row, col):
        """
        :type row: int
        :type col: int
        :rtype: int
        """
        for (row1, col1, row2, col2, newValue) in reversed(self.__updates):
            if row1 <= row <= row2 and col1 <= col <= col2:
                return newValue
        return self.__rectangle[row][col]


# Time:  ctor:   O(1)
#        update: O(m * n)
#        get:    O(1)
# Space: O(1)
class SubrectangleQueries2(object):

    def __init__(self, rectangle):
        """
        :type rectangle: List[List[int]]
        """
        self.__rectangle = rectangle
        

    def updateSubrectangle(self, row1, col1, row2, col2, newValue):
        """
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :type newValue: int
        :rtype: None
        """
        for r in xrange(row1, row2+1):
            for c in xrange(col1, col2+1):
                self.__rectangle[r][c] = newValue

    def getValue(self, row, col):
        """
        :type row: int
        :type col: int
        :rtype: int
        """
        return self.__rectangle[row][col]
