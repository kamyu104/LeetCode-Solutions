# Time:  O(n)
# Space: O(1)

class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        result = []
        i = 0
        while i < len(intervals) and newInterval[0] > intervals[i][1]:
            result += intervals[i],
            i += 1
        while i < len(intervals) and newInterval[1] >= intervals[i][0]:
            newInterval = [min(newInterval[0], intervals[i][0]),
                           max(newInterval[1], intervals[i][1])]
            i += 1
        result.append(newInterval)
        result.extend(intervals[i:])
        return result
