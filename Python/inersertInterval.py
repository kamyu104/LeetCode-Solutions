# Time:  O(n)
# Space: O(1)
#
# Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
# 
# You may assume that the intervals were initially sorted according to their start times.
# 
# Example 1:
# Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
# 
# Example 2:
# Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
# 
# This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
#

# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e
        
    def __repr__(self):
        return "[{}, {}]".format(self.start, self.end)

class Solution:
    # @param intervals, a list of Intervals
    # @param newInterval, a Interval
    # @return a list of Interval
    def insert(self, intervals, newInterval):
        return self.merge(intervals + [newInterval])
        
    def merge(self, intervals):
        if len(intervals) == 0:
            return intervals
        intervals.sort(key = lambda x: x.start)
        result = [intervals[0]]
        for i in range(1, len(intervals)):
            prev, current = result[-1], intervals[i]
            if current.start <= prev.end: 
                prev.end = max(prev.end, current.end)
            else:
                result.append(current)
        return result

if __name__ == "__main__":
    print Solution().insert([Interval(1, 2), Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16)], Interval(4, 9))