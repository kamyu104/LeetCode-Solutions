# Time:  O(n + qlogn)
# Space: O(n)

# online solution, segment tree, binary search
class Solution(object):
    def leftmostBuildingQueries(self, heights, queries):
        """
        :type heights: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        # Range Maximum Query
        class SegmentTree(object):
            def __init__(self, N,
                         build_fn=lambda _: None,
                         query_fn=lambda x, y: max(x, y)):
                self.tree = [None]*(2*2**((N-1).bit_length()))
                self.build_fn = build_fn
                self.query_fn = query_fn
                self.build(0, N-1, 1)
            
            def build(self, left, right, idx):
                if left == right:
                    self.tree[idx] = self.build_fn(left)
                    return 
                mid = left + (right-left)//2
                self.build(left, mid, idx*2)
                self.build(mid+1, right, idx*2+1)
                self.tree[idx] = self.query_fn(self.tree[idx*2], self.tree[idx*2+1])

            def binary_search(self, L, R, left, right, idx, h):
                if right < L or left > R:
                    return -1
                if L <= left and right <= R:
                    if not self.tree[idx] > h:
                        return -1
                    if left == right:
                        return left
                mid = left + (right-left)//2
                i = self.binary_search(L, R, left, mid, idx*2, h)
                return i if i != -1 else self.binary_search(L, R, mid+1, right, idx*2+1, h)

        def build(i):
            return heights[i]

        result = [-1]*len(queries)
        st = SegmentTree(len(heights), build_fn=build)
        for i, (a, b) in enumerate(queries):
            if a > b:
                a, b = b, a
            if a == b or heights[a] < heights[b]:
                result[i] = b
                continue
            result[i] = st.binary_search(b+1, len(heights)-1, 0, len(heights)-1, 1, heights[a])
        return result


# Time:  O(n + qlogq)
# Space: O(n + q)
import heapq


# offline solution, heap
class Solution2(object):
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


# Time:  O(n + qlogn)
# Space: O(n + q)
# offline solution, mono stack, binary search
class Solution3(object):
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
