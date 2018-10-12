# Time:  O(n^2)
# Space: O(n)

class MyCalendarTwo(object):

    def __init__(self):
        self.__overlaps = []
        self.__calendar = []


    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        for i, j in self.__overlaps:
            if start < j and end > i:
                return False
        for i, j in self.__calendar:
            if start < j and end > i:
                self.__overlaps.append((max(start, i), min(end, j)))
        self.__calendar.append((start, end))
        return True



