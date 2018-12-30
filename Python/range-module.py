# Time:  addRange:    O(n)
#        removeRange: O(n)
#        queryRange:  O(logn)
# Space: O(n)

import bisect


class RangeModule(object):

    def __init__(self):
        self.__intervals = []

    def addRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: void
        """
        tmp = []
        i = 0
        for interval in self.__intervals:
            if right < interval[0]:
                tmp.append((left, right))
                break
            elif interval[1] < left:
                tmp.append(interval)
            else:
                left = min(left, interval[0])
                right = max(right, interval[1])
            i += 1
        if i == len(self.__intervals):
            tmp.append((left, right))
        while i < len(self.__intervals):
            tmp.append(self.__intervals[i])
            i += 1
        self.__intervals = tmp

    def queryRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: bool
        """
        i = bisect.bisect_left(self.__intervals, (left, float("inf")))
        if i: i -= 1
        return bool(self.__intervals) and \
               self.__intervals[i][0] <= left and \
               right <= self.__intervals[i][1]

    def removeRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: void
        """
        tmp = []
        for interval in self.__intervals:
            if interval[1] <= left or interval[0] >= right:
                tmp.append(interval)
            else:
                if interval[0] < left:
                    tmp.append((interval[0], left))
                if right < interval[1]:
                    tmp.append((right, interval[1]))
        self.__intervals = tmp



