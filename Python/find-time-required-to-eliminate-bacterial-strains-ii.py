# Time:  O(nlogn)
# Space: O(1)

import heapq


# heap, greedy
class Solution(object):
    def minEliminationTime(self, timeReq, splitTime):
        """
        :type timeReq: List[int]
        :type splitTime: int
        :rtype: int
        """
        heapq.heapify(timeReq)
        for _ in xrange(len(timeReq)-1):
            heapq.heappush(timeReq, max(heapq.heappop(timeReq), heapq.heappop(timeReq))+splitTime)
        return timeReq[0]
