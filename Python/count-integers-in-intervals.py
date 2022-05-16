# Time:  ctor:  O(1)
#        add:   O(logn), amortized
#        count: O(1)
# Space: O(n)

from sortedcontainers import SortedList


# design, sortedlist
class CountIntervals(object):

    def __init__(self):
        self.__sl = SortedList()
        self.__cnt = 0

    def add(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: None
        """
        i = self.__sl.bisect_right((left,))
        if i-1 >= 0 and self.__sl[i-1][1]+1 >= left:
            i -= 1
            left = self.__sl[i][0]
        to_remove = []
        for i in xrange(i, len(self.__sl)):
            if not (right+1 >= self.__sl[i][0]):
                break
            right = max(right, self.__sl[i][1])
            self.__cnt -= self.__sl[i][1]-self.__sl[i][0]+1
            to_remove.append(i)
        while to_remove:
            del self.__sl[to_remove.pop()]
        self.__sl.add((left, right))
        self.__cnt += right-left+1

    def count(self):
        """
        :rtype: int
        """
        return self.__cnt
