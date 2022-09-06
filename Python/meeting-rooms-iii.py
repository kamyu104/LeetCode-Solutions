# Time:  O(mlogm + n + mlogn)
# Space: O(n)

import heapq


# one heap solution
class Solution(object):
    def mostBooked(self, n, meetings):
        """
        :type n: int
        :type meetings: List[List[int]]
        :rtype: int
        """
        meetings.sort()
        min_heap = [(meetings[0][0], i) for i in xrange(n)]
        result = [0]*n
        for s, e in meetings:
            while min_heap and min_heap[0][0] < s:
                _, i = heapq.heappop(min_heap)
                heapq.heappush(min_heap, (s, i))
            e2, i = heapq.heappop(min_heap)
            heapq.heappush(min_heap, (e2+(e-s), i))
            result[i] += 1
        return max(xrange(n), key=lambda x:result[x])


# Time:  O(mlogm + n + mlogn)
# Space: O(n)
import heapq


# two heaps solution
class Solution2(object):
    def mostBooked(self, n, meetings):
        """
        :type n: int
        :type meetings: List[List[int]]
        :rtype: 
        """
        meetings.sort()
        unused, used = range(n), []
        result = [0]*n
        for s, e in meetings:
            while used and used[0][0] <= s:
                _, i = heapq.heappop(used)
                heapq.heappush(unused, i)
            if unused:
                i = heapq.heappop(unused)
                heapq.heappush(used, (e, i))
            else:
                e2, i = heapq.heappop(used)
                heapq.heappush(used, (e2+(e-s), i))
            result[i] += 1
        return max(xrange(n), key=lambda x:result[x])
