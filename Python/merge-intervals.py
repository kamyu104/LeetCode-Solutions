# Time:  O(nlogn)
# Space: O(1)

class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

    def __repr__(self):
        return "[{}, {}]".format(self.start, self.end)


class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if not intervals:
            return intervals

        intervals.sort(key=lambda x: x.start)
        iterator = iter(intervals)
        result = [next(iterator)]
        for current in iterator:
            prev = result[-1]
            if current.start <= prev.end:
                prev.end = max(current.end, prev.end)
            else:
                result.append(current)

        return result
