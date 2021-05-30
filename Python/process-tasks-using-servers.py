# Time:  O(n + mlogn)
# Space: O(n)

import heapq


class Solution(object):
    def assignTasks(self, servers, tasks):
        """
        :type servers: List[int]
        :type tasks: List[int]
        :rtype: List[int]
        """
        idle = [(servers[i], i) for i in xrange(len(servers))]
        working = []
        heapq.heapify(idle)
        result = []
        t = 0
        for i in xrange(len(tasks)):
            t = max(t, i) if idle else working[0][0]
            while working and working[0][0] <= t:
                _, w, idx = heapq.heappop(working)
                heapq.heappush(idle, (w, idx))
            w, idx = heapq.heappop(idle)
            heapq.heappush(working, (t+tasks[i], w, idx))
            result.append(idx)
        return result
