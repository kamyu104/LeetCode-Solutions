# Time:  O(nlogn)
# Space: O(n)

from sortedcontainers import SortedList


# sorted list
class Solution(object):
    def shortestDistanceAfterQueries(self, n, queries):
        """
        :type n: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        sl = SortedList(xrange(n))
        result = []
        for u, v in queries:
            for i in reversed(xrange(sl.bisect_right(u), sl.bisect_left(v))): 
                sl.pop(i)
            result.append(len(sl)-1)
        return result
