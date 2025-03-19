# Time:  ctor:      O(1)
#        setCell:   O(1)
#        resetCell: O(1)
#        getValue:  O(1)
# Space: O(n)

import collections


# hash table
class Spreadsheet(object):

    def __init__(self, rows):
        """
        :type rows: int
        """
        self.__lookup = collections.defaultdict(int)


    def setCell(self, cell, value):
        """
        :type cell: str
        :type value: int
        :rtype: None
        """
        self.__lookup[cell] = value


    def resetCell(self, cell):
        """
        :type cell: str
        :rtype: None
        """
        if cell in self.__lookup:
            del self.__lookup[cell]


    def getValue(self, formula):
        """
        :type formula: str
        :rtype: int
        """
        left, right = formula[1 :].split('+')
        x = self.__lookup.get(left, 0) if left[0].isalpha() else int(left)
        y = self.__lookup.get(right, 0) if right[0].isalpha() else int(right)
        return x+y
