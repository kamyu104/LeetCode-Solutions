# Time:  O((w * b) * log(w * b))
# Space: O(w * b)

import heapq


class Solution(object):
    def assignBikes(self, workers, bikes):
        """
        :type workers: List[List[int]]
        :type bikes: List[List[int]]
        :rtype: List[int]
        """
        def manhattan(p1, p2):
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])
        
        distances = [[] for _ in xrange(len(workers))]
        for i in xrange(len(workers)):
            for j in xrange(len(bikes)):
                distances[i].append((manhattan(workers[i], bikes[j]), i, j))
            distances[i].sort(reverse = True)
        
        result = [None] * len(workers)
        lookup = set()
        min_heap = []
        for i in xrange(len(workers)):
            heapq.heappush(min_heap, distances[i].pop())
        while len(lookup) < len(workers):
            _, worker, bike = heapq.heappop(min_heap)
            if bike not in lookup:
                result[worker] = bike
                lookup.add(bike)
            else:
                heapq.heappush(min_heap, distances[worker].pop())
        return result
