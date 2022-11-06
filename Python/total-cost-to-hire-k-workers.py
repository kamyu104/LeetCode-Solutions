# Time:  O(c + klogc)
# Space: O(c)

import heapq


# heap, two pointers
class Solution(object):
    def totalCost(self, costs, k, candidates):
        """
        :type costs: List[int]
        :type k: int
        :type candidates: int
        :rtype: int
        """
        left, right = candidates, max(len(costs)-candidates, candidates)-1
        min_heap1, min_heap2 = costs[:left], costs[right+1:]
        heapq.heapify(min_heap1), heapq.heapify(min_heap2)
        result = 0
        for _ in xrange(k):
            if not min_heap2 or (min_heap1 and min_heap1[0] <= min_heap2[0]):
                result += heapq.heappop(min_heap1)
                if left <= right:
                    heapq.heappush(min_heap1, costs[left])
                    left += 1
            else:
                result += heapq.heappop(min_heap2)
                if left <= right:
                    heapq.heappush(min_heap2, costs[right])
                    right -= 1
        return result
