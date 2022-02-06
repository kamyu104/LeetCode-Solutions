# Time:  O(nlogn)
# Space: O(n)

import collections
import heapq


# line sweep, heap
class Solution(object):
    def amountPainted(self, paint):
        """
        :type paint: List[List[int]]
        :rtype: List[int]
        """
        points = collections.defaultdict(list)
        for i, (s, e) in enumerate(paint):
            points[s].append((True, i))
            points[e].append((False, i))
        min_heap = []
        lookup = [False]*len(paint)
        result = [0]*len(paint)
        prev = -1
        for pos in sorted(points.iterkeys()):
            while min_heap and lookup[min_heap[0]]:
                heapq.heappop(min_heap)
            if min_heap:
                result[min_heap[0]] += pos-prev
            prev = pos
            for t, i in points[pos]:
                if t:
                    heapq.heappush(min_heap, i)
                else:
                    lookup[i] = True
        return result
                    
            
# Time:  O(nlogn)
# Space: O(n)
from sortedcontainers import SortedList


# line sweep, sorted list
class Solution2(object):
    def amountPainted(self, paint):
        """
        :type paint: List[List[int]]
        :rtype: List[int]
        """
        points = collections.defaultdict(list)
        for i, (s, e) in enumerate(paint):
            points[s].append((True, i))
            points[e].append((False, i))
        sl = SortedList()
        result = [0]*len(paint)
        prev = -1
        for pos in sorted(points.iterkeys()):
            if sl:
                result[sl[0]] += pos-prev
            prev = pos
            for t, i in points[pos]:
                if t:
                    sl.add(i)
                else:
                    sl.remove(i)
        return result


class SegmentTree(object):
    def __init__(self, N,
                 build_fn=lambda x: 0,
                 query_fn=lambda x, y: y if x is None else x+y,
                 update_fn=lambda x, y: y):
        self.tree = [None]*(2*N)
        self.lazy = [None]*len(self.tree)
        self.base = len(self.tree)//2
        self.H = (self.base-1).bit_length()
        self.query_fn = query_fn
        self.update_fn = update_fn
        for i in xrange(self.base, self.base+N):
            self.tree[i] = build_fn(i-self.base)
        for i in reversed(xrange(1, self.base)):
            self.tree[i] = query_fn(self.tree[2*i], self.tree[2*i+1])
        self.count = [1]*(2*N)
        for i in reversed(xrange(1, N)):
            self.count[i] = self.count[2*i] + self.count[2*i+1]

    def __apply(self, x, val):
        self.tree[x] = self.update_fn(self.tree[x], val*self.count[x])
        if x < self.base:
            self.lazy[x] = self.update_fn(self.lazy[x], val)

    def __push(self, x):
        n = 2**self.H
        while n != 1:
            y = x // n
            if self.lazy[y] is not None:
                self.__apply(y*2, self.lazy[y])
                self.__apply(y*2 + 1, self.lazy[y])
                self.lazy[y] = None
            n //= 2

    def update(self, L, R, h):
        def pull(x):
            while x > 1:
                x //= 2
                self.tree[x] = self.query_fn(self.tree[x*2], self.tree[x*2+1])
                if self.lazy[x] is not None:
                    self.tree[x] = self.update_fn(self.tree[x], self.lazy[x]*self.count[x])

        if L > R:
            return
        L += self.base
        R += self.base
        self.__push(L)  # key point
        self.__push(R)  # key point
        L0, R0 = L, R
        while L <= R:
            if L & 1:
                self.__apply(L, h)
                L += 1
            if R & 1 == 0:
                self.__apply(R, h)
                R -= 1
            L //= 2
            R //= 2
        pull(L0)
        pull(R0)

    def query(self, L, R):
        result = None
        if L > R:
            return result

        L += self.base
        R += self.base
        self.__push(L)
        self.__push(R)
        while L <= R:
            if L & 1:
                result = self.query_fn(result, self.tree[L])
                L += 1
            if R & 1 == 0:
                result = self.query_fn(result, self.tree[R])
                R -= 1
            L //= 2
            R //= 2
        return result


# Time:  O(nlogr), r is the max position
# Space: O(r)
# segment tree
class SolutionTLE(object):
    def amountPainted(self, paint):
        """
        :type paint: List[List[int]]
        :rtype: List[int]
        """
        result = []
        st = SegmentTree(max(e for _, e in paint))
        for s, e in paint:
            cnt = st.query(s, e-1)
            st.update(s, e-1, 1)
            result.append(st.query(s, e-1)-cnt)
        return result
