# Time:  O(n)
# Space: O(1)

class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

    def __repr__(self):
        return "[{}, {}]".format(self.start, self.end)


class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        result = []
        i = 0
        while i < len(intervals) and newInterval.start > intervals[i].end:
            result += intervals[i],
            i += 1
        while i < len(intervals) and newInterval.end >= intervals[i].start:
            newInterval = Interval(min(newInterval.start, intervals[i].start), \
                                   max(newInterval.end, intervals[i].end))
            i += 1
        result += newInterval,
        result += intervals[i:]
        return result


