# Time:  O(k + nlogk)
# Space: O(k)

import heapq


# heap, simulation
class Solution(object):
    def findCrossingTime(self, n, k, time):
        """
        :type n: int
        :type k: int
        :type time: List[List[int]]
        :rtype: int
        """
        left_ware, left_bridge, right_bridge, right_ware = [], [(-(time[i][0]+time[i][2]), -i) for i in xrange(k)], [], []
        heapq.heapify(left_bridge)
        result = 0
        while n:
            while left_ware and left_ware[0][0] <= result:
                _, i = heapq.heappop(left_ware)
                heapq.heappush(left_bridge, (-(time[i][0]+time[i][2]), -i))
            while right_ware and right_ware[0][0] <= result:
                _, i = heapq.heappop(right_ware)
                heapq.heappush(right_bridge, (-(time[i][0]+time[i][2]), -i))
            if right_bridge:
                _, i = heapq.heappop(right_bridge)
                i = -i
                result += time[i][2]
                heapq.heappush(left_ware, (result+time[i][3], i))
                n -= 1
            elif left_bridge and n-len(right_ware):
                _, i = heapq.heappop(left_bridge)
                i = -i
                result += time[i][0]
                heapq.heappush(right_ware, (result+time[i][1], i))
            else:
                result = min(left_ware[0][0] if left_ware else float("inf"),
                             right_ware[0][0] if right_ware else float("inf"))
        return result
