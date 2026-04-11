# Time:  O(nlogn)
# Space: O(n)

import bisect


# sort, binary search
class Solution(object):
    def maximumTeamSize(self, startTime, endTime):
        """
        :type startTime: List[int]
        :type endTime: List[int]
        :rtype: int
        """
        sorted_start = sorted(startTime)
        sorted_end = sorted(endTime)
        return max(bisect.bisect_right(sorted_start, endTime[i])-bisect.bisect_left(sorted_end, startTime[i]) for i in xrange(len(startTime)))
