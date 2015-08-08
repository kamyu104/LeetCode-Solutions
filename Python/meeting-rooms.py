# Time:  O(nlogn)
# Space: O(n)
#
# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    # @param {Interval[]} intervals
    # @return {boolean}
    def canAttendMeetings(self, intervals):
        intervals.sort(key=lambda x: x.start)
    
        for i in xrange(1, len(intervals)):
            if intervals[i].start < intervals[i-1].end:
                return False
        return True
