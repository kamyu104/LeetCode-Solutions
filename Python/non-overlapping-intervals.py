# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        intervals.sort(key=lambda interval: interval.start)
        result, prev = 0, 0
        for i in xrange(1, len(intervals)):
            if intervals[i].start < intervals[prev].end:
                if intervals[i].end < intervals[prev].end:
                    prev = i
                result += 1
            else:
                prev = i
        return result

