# Time:  O(nlogn)
# Space: O(n)

import itertools
import bisect


class Solution(object):
    def jobScheduling(self, startTime, endTime, profit):
        """
        :type startTime: List[int]
        :type endTime: List[int]
        :type profit: List[int]
        :rtype: int
        """
        jobs = sorted(itertools.izip(endTime, startTime, profit))
        dp = [(0, 0)]
        for e, s, p in jobs:
            i = bisect.bisect_right(dp, (s+1, 0))-1
            if dp[i][1]+p > dp[-1][1]:
                dp.append((e, dp[i][1]+p))
        return dp[-1][1]


# Time:  O(nlogn)
# Space: O(n)
import heapq
class Solution(object):
    def jobScheduling(self, startTime, endTime, profit):
        """
        :type startTime: List[int]
        :type endTime: List[int]
        :type profit: List[int]
        :rtype: int
        """
        min_heap = zip(startTime, endTime, profit)
        heapq.heapify(min_heap)
        result = 0
        while min_heap:
            s, e, p = heapq.heappop(min_heap)
            if s < e:
                heapq.heappush(min_heap, (e, s, result+p))
            else:
                result = max(result, p)
        return result
