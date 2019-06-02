# Time:  O((w * b * 2^b) * log(w * b * 2^b))
# Space: O(w * b * 2^b)

import heapq


class Solution(object):
    def assignBikes(self, workers, bikes):
        """
        :type workers: List[List[int]]
        :type bikes: List[List[int]]
        :rtype: int
        """
        def manhattan(p1, p2):
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])
        
        min_heap = [(0, 0, 0)]
        lookup = set()
        while min_heap:
            cost, i, taken = heapq.heappop(min_heap)
            if (i, taken) in lookup:
                continue
            lookup.add((i, taken))
            if i == len(workers):
                return cost
            for j in xrange(len(bikes)):
                if taken & (1<<j):
                    continue
                heapq.heappush(min_heap, (cost+manhattan(workers[i], bikes[j]),  # O(b)
                                          i+1,            # O(w)
                                          taken|(1<<j)))  # O(2^b)


# Time:  O(w * b * 2^b)
# Space: O(w * b * 2^b)
class Solution2(object):
    def assignBikes(self, workers, bikes):
        """
        :type workers: List[List[int]]
        :type bikes: List[List[int]]
        :rtype: int
        """
        def manhattan(p1, p2):
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])
        
        dp = [[float("inf")] * ((1<<len(bikes))) for _ in xrange(len(workers)+1)]
        dp[0][0] = 0
        for i in xrange(len(workers)):
            for j in xrange(len(bikes)):
                for taken in xrange((1<<len(bikes))):
                    if taken & (1<<j):
                        continue
                    dp[i+1][taken|(1<<j)] = min(dp[i+1][taken|(1<<j)],
                                                dp[i][taken] +
                                                manhattan(workers[i], bikes[j]))
        return min(dp[-1])
