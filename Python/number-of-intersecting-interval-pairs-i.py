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


# Time:  O(n^2)
# Space: O(1)
# brute force
class Solution2(object):
    def countIntersectingIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        def check(i, j):
            return max(intervals[i][0], intervals[j][0]) <= min(intervals[i][1], intervals[j][1])

        return sum(check(i, j) for i in xrange(len(intervals)) for j in xrange(i+1, len(intervals)))
