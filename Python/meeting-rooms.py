# Time:  O(nlogn)
# Space: O(n)

class Solution(object):
    # @param {Interval[]} intervals
    # @return {boolean}
    def canAttendMeetings(self, intervals):
        intervals.sort(key=lambda x: x.start)

        for i in xrange(1, len(intervals)):
            if intervals[i].start < intervals[i-1].end:
                return False
        return True

