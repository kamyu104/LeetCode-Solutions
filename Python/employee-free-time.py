# Time:  O(m * logn), m is the number of schedule, n is the number of employees, m >= n
# Space: O(n)

# We are given a list schedule of employees, which represents the working time for each employee.
# Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.
# Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.
#
# Example 1:
# Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
# Output: [[3,4]]
# Explanation:
# There are a total of three employees, and all common
# free time intervals would be [-inf, 1], [3, 4], [10, inf].
# We discard any intervals that contain inf as they aren't finite.
#
# Example 2:
# Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
# Output: [[5,6],[7,9]]
# (Even though we are representing Intervals in the form [x, y],
#  the objects inside are Intervals, not lists or arrays.
#  For example, schedule[0][0].start = 1, schedule[0][0].end = 2,
# and schedule[0][0][0] is not defined.)
#
# Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.
#
# Note:
# - schedule and schedule[i] are lists with lengths in range [1, 50].
# - 0 <= schedule[i].start < schedule[i].end <= 10^8.

# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def employeeFreeTime(self, schedule):
        """
        :type schedule: List[List[Interval]]
        :rtype: List[Interval]
        """
        result = []
        min_heap = [(emp[0].start, eid, 0) for eid, emp in enumerate(schedule)]
        heapq.heapify(min_heap)
        last_end = -1
        while min_heap:
            t, eid, i = heapq.heappop(min_heap)
            if 0 <= last_end < t:
                result.append(Interval(last_end, t))
            last_end = max(last_end, schedule[eid][i].end)
            if i+1 < len(schedule[eid]):
                heapq.heappush(min_heap, (schedule[eid][i+1].start, eid, i+1))
        return result
