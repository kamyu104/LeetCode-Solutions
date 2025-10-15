# Time:  O(nlogn)
# Space: O(n)

import heapq


# greedy, heap
class Solution(object):
    def maxTransactions(self, transactions):
        """
        :type transactions: List[int]
        :rtype: int
        """
        min_heap = []
        curr = 0
        for x in transactions:
            heapq.heappush(min_heap, x)
            curr += x
            if curr < 0:
                curr -= heapq.heappop(min_heap)
        return len(min_heap)
