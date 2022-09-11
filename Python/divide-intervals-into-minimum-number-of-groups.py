# Time:  O(nlogn)
# Space: O(n)

import collections


# sort, line sweep
class Solution(object):
    def minGroups(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        events = collections.Counter()
        for l, r in intervals:
            events[l] += 1
            events[r+1] -= 1
        result = curr = 0
        for t in sorted(events.iterkeys()):
            curr += events[t]
            result = max(result, curr)
        return result
