# Time:  O(n^2)
# Space: O(n)

import bisect


class MyCalendarThree(object):

    def __init__(self):
        self.__books = []


    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: int
        """
        i = bisect.bisect_left(self.__books, (start, 1))
        if i < len(self.__books) and self.__books[i][0] == start:
            self.__books[i] = (self.__books[i][0], self.__books[i][1]+1)
        else:
            self.__books.insert(i, (start, 1))

        j = bisect.bisect_left(self.__books, (end, 1))
        if j < len(self.__books) and self.__books[j][0] == end:
            self.__books[j] = (self.__books[j][0], self.__books[j][1]-1)
        else:
            self.__books.insert(j, (end, -1))

        result, cnt = 0, 0
        for book in self.__books:
            cnt += book[1]
            result = max(result, cnt)
        return result



