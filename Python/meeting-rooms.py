# Time:  O(nlogn)
# Space: O(n)

class Solution(object):
    def canAttendMeetings(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: bool
        """
        intervals.sort(key=lambda x: x[0])

        for i in xrange(1, len(intervals)):
            if intervals[i][0] < intervals[i-1][1]:
                return False
        return True
