# Time:  ctor:       O(t * max_m), t is the number of tables, max_m is the max number of columns in all tables
#        insertRow:  O(m), m is the number of columns
#        deleteRow:  O(1)
#        selectCell: O(m)
# Space: O(d), d is the total size of data

import itertools


# hash table
class SQL(object):

    def __init__(self, names, columns):
        """
        :type names: List[str]
        :type columns: List[int]
        """
        self.__table = {name:[column] for name, column in itertools.izip(names, columns)}

    def insertRow(self, name, row):
        """
        :type name: str
        :type row: List[str]
        :rtype: None
        """
        row.append("")  # soft delete
        self.__table[name].append(row)

    def deleteRow(self, name, rowId):
        """
        :type name: str
        :type rowId: int
        :rtype: None
        """
        self.__table[name][rowId][-1] = "deleted"  # soft delete

    def selectCell(self, name, rowId, columnId):
        """
        :type name: str
        :type rowId: int
        :type columnId: int
        :rtype: str
        """
        return self.__table[name][rowId][columnId-1] if self.__table[name][rowId][-1] == "" else ""
