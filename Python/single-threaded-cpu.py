# Time:  O(nlogn)
# Space: O(n)

import heapq


class Solution(object):
    def getOrder(self, tasks):
        """
        :type tasks: List[List[int]]
        :rtype: List[int]
        """
        idx = range(len(tasks))
        idx.sort(key=lambda x: tasks[x][0])
        result, min_heap = [], []
        i, time = 0, tasks[idx[0]][0]
        while i < len(idx) or min_heap:
            while i < len(idx) and tasks[idx[i]][0] <= time:
                heapq.heappush(min_heap, (tasks[idx[i]][1], idx[i]))
                i += 1
            if not min_heap:
                time = tasks[idx[i]][0]
                continue
            t, j = heapq.heappop(min_heap)
            time += t
            result.append(j)
        return result
