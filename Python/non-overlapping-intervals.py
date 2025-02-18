# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        intervals.sort(key=lambda interval: interval[1])
        result, right = 0, float("-inf")
        for l, r in intervals:
            if l < right:
                result += 1
            else:
                right = r
        return result


# Time:  O(nlogn)
# Space: O(1)
class Solution2(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        intervals.sort(key=lambda interval: interval[0])
        result, prev = 0, 0
        for i in xrange(1, len(intervals)):
            if intervals[i][0] < intervals[prev][1]:
                if intervals[i][1] < intervals[prev][1]:
                    prev = i
                result += 1
            else:
                prev = i
        return result

