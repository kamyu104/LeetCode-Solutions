# Time:  O(nlogn)
# Space: O(n)

# sort, line sweep
class Solution(object):
    def countIntersectingIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        events = []
        for l, r in intervals:
            events.append((l, +1))
            events.append((r+1, -1))
        events.sort()
        result = cnt = 0
        for _, c in events:
            if c == +1:
                result += cnt
            cnt += c
        return result
