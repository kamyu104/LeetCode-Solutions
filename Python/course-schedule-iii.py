# Time:  O(nlogn)
# Space: O(k), k is the number of courses you can take

import collections
import heapq


class Solution(object):
    def scheduleCourse(self, courses):
        """
        :type courses: List[List[int]]
        :rtype: int
        """
        courses.sort(key=lambda t_end: t_end[1])
        max_heap = []
        now = 0
        for t, end in courses:
            now += t
            heapq.heappush(max_heap, -t)
            if now > end:
                now += heapq.heappop(max_heap)
        return len(max_heap)

