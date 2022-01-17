# Time:  O(nlogm)
# Space: O(1)

import heapq


# greedy
class Solution(object):
    def maxRunTime(self, n, batteries):
        """
        :type n: int
        :type batteries: List[int]
        :rtype: int
        """
        total = sum(batteries)
        for i in xrange(len(batteries)):
            batteries[i] = -batteries[i]  # max_heap
        heapq.heapify(batteries)
        while -batteries[0] > total//n:
            n -= 1
            total -= -heapq.heappop(batteries)
        return total//n


# Time:  O(nlogr), r is the range of possible minutes
# Space: O(1)
# binary search
class Solution2(object):
    def maxRunTime(self, n, batteries):
        """
        :type n: int
        :type batteries: List[int]
        :rtype: int
        """
        def check(n, batteries, x):
            return sum(min(b, x) for b in batteries) >= n*x

        left, right = min(batteries), sum(batteries)//n
        while left <= right:
            mid = left + (right-left)//2
            if not check(n, batteries, mid):
                right = mid-1
            else:
                left = mid+1
        return right
