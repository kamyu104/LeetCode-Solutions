# Time:  O(n + qlogq)
# Space: O(n + q)

import heapq


# heap
class Solution(object):
    def leftmostBuildingQueries(self, heights, queries):
        """
        :type heights: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        result = [-1]*len(queries)
        qs = [[] for _ in xrange(len(heights))]
        for i, (a, b) in enumerate(queries):
            if a > b:
                a, b = b, a
            if a == b or heights[a] < heights[b]:
                result[i] = b
            else:
                qs[b].append((heights[a], i))
        min_heap = []
        for i, h in enumerate(heights):
            for q in qs[i]:
                heapq.heappush(min_heap, q)
            while min_heap and min_heap[0][0] < h:
                _, j = heapq.heappop(min_heap)
                result[j] = i
        return result


# Time:  O(q + qlogn)
# Space: O(n + q)
# mono stack, binary search
class Solution2(object):
    def leftmostBuildingQueries(self, heights, queries):
        """
        :type heights: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def binary_search_right(left, right, check):
            while left <= right:
                mid = left + (right-left)//2
                if not check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return right

        result = [-1]*len(queries)
        qs = [[] for _ in xrange(len(heights))]
        for i, (a, b) in enumerate(queries):
            if a > b:
                a, b = b, a
            if a == b or heights[a] < heights[b]:
                result[i] = b
            else:
                qs[b].append((heights[a], i))
        stk = []
        for b in reversed(xrange(len(heights))):
            while stk and stk[-1][0] <= heights[b]:
                stk.pop()
            stk.append((heights[b], b))
            for ha, i in qs[b]:
                j = binary_search_right(0, len(stk)-1, lambda x: stk[x][0] > ha)
                if j >= 0:
                    result[i] = stk[j][1]
        return result
