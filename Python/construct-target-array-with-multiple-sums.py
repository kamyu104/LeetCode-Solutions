# Time:  O(log(max(t)) * logn)
# Space: O(n)

import heapq


class Solution(object):
    def isPossible(self, target):
        """
        :type target: List[int]
        :rtype: bool
        """
        # (1) x + remain = y
        # (2) y + remain = total
        # (1) - (2) => x - y = y - total
        #           => x = 2*y - total
        total = sum(target)
        max_heap = [-x for x in target]
        heapq.heapify(max_heap)
        while total != len(target):
            y = -heapq.heappop(max_heap)
            remain = total-y
            x = y-remain
            if x <= 0:
                return False
            if x > remain:  # for case [1, 1000000000]
                x = x%remain + remain
            heapq.heappush(max_heap, -x)
            total = x+remain
        return True
