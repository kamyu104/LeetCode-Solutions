# Time:  addRange:    O(n)
#        removeRange: O(n)
#        queryRange:  O(logn)
# Space: O(n)

# A Range Module is a module that tracks ranges of numbers.
# Your task is to design and implement the following interfaces in an efficient manner.
# - addRange(int left, int right) Adds the half-open interval [left, right),
#   tracking every real number in that interval.
#   Adding an interval that partially overlaps with currently tracked numbers should
#   add any numbers in the interval [left, right) that are not already tracked.
# - queryRange(int left, int right) Returns true if and only if
#   every real number in the interval [left, right) is currently being tracked.
# - removeRange(int left, int right) Stops tracking every real number currently being tracked
#   in the interval [left, right).
#
# Example 1:
# addRange(10, 20): null
# removeRange(14, 16): null
# queryRange(10, 14): true (Every number in [10, 14) is being tracked)
# queryRange(13, 15): false (Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
# queryRange(16, 17): true (The number 16 in [16, 17) is still being tracked, despite the remove operation)
#
# Note:
# - A half open interval [left, right) denotes all real numbers left <= x < right.
# - 0 < left < right < 10^9 in all calls to addRange, queryRange, removeRange.
# - The total number of calls to addRange in a single test case is at most 1000.
# - The total number of calls to queryRange in a single test case is at most 5000.
# - The total number of calls to removeRange in a single test case is at most 1000.

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
                tmp.append(interval);
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


# Your RangeModule object will be instantiated and called as such:
# obj = RangeModule()
# obj.addRange(left,right)
# param_2 = obj.queryRange(left,right)
# obj.removeRange(left,right)
