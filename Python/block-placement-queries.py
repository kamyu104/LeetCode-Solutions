# Time:  O(qlogq)
# Space: O(q)

from sortedcontainers import SortedList


# sorted list, bit, fenwick tree
class Solution(object):
    def getResults(self, queries):
        """
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        class BIT(object):  # 0-indexed.
            def __init__(self, n, default=0, fn=lambda x, y: x+y):
                self.__bit = [default]*(n+1)  # Extra one for dummy node.
                self.__default = default
                self.__fn = fn

            def update(self, i, val):
                i += 1  # Extra one for dummy node.
                while i < len(self.__bit):
                    self.__bit[i] = self.__fn(self.__bit[i], val)
                    i += (i & -i)

            def query(self, i):
                i += 1  # Extra one for dummy node.
                ret = self.__default
                while i > 0:
                    ret = self.__fn(ret, self.__bit[i])
                    i -= (i & -i)
                return ret
            
        sl = SortedList(q[1] for q in queries if q[0] == 1)
        val_to_idx = {x:i for i, x in enumerate(sl)}
        bit = BIT(len(val_to_idx), fn=max)
        for i in xrange(len(sl)):
            bit.update(val_to_idx[sl[i]], sl[i]-(sl[i-1] if i-1 >= 0 else 0))
        result = []
        for q in reversed(queries):
            i = sl.bisect_left(q[1])
            if q[0] == 1:
                if i+1 < len(sl):
                    bit.update(val_to_idx[sl[i+1]], sl[i+1]-(sl[i-1] if i-1 >= 0 else 0))
                del sl[i]
            else:
                result.append(q[1]-(sl[i-1] if i-1 >= 0 else 0) >= q[2] or (i-1 >= 0 and bit.query(val_to_idx[sl[i-1]]) >= q[2]))
        result.reverse()
        return result


# Time:  O(qlogq)
# Space: O(q)
from sortedcontainers import SortedList


# sorted list, segment tree
class Solution2(object):
    def getResults(self, queries):
        """
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        # Template:
        # https://github.com/kamyu104/LeetCode-Solutions/blob/master/Python/booking-concert-tickets-in-groups.py
        class SegmentTree(object):
            def __init__(self, N,
                        build_fn=lambda _: None,
                        query_fn=lambda x, y: y if x is None else x if y is None else max(x, y),
                        update_fn=lambda x: x):
                self.tree = [None]*(1<<((N-1).bit_length()+1))
                self.base = len(self.tree)>>1
                self.query_fn = query_fn
                self.update_fn = update_fn
                for i in xrange(self.base, self.base+N):
                    self.tree[i] = build_fn(i-self.base)
                for i in reversed(xrange(1, self.base)):
                    self.tree[i] = query_fn(self.tree[i<<1], self.tree[(i<<1)+1])

            def update(self, i, h):
                x = self.base+i
                self.tree[x] = self.update_fn(h)
                while x > 1:
                    x >>= 1
                    self.tree[x] = self.query_fn(self.tree[x<<1], self.tree[(x<<1)+1])

            def query(self, L, R):
                L += self.base
                R += self.base
                left = right = None
                while L <= R:
                    if L & 1:
                        left = self.query_fn(left, self.tree[L])
                        L += 1
                    if R & 1 == 0:
                        right = self.query_fn(self.tree[R], right)
                        R -= 1
                    L >>= 1
                    R >>= 1
                return self.query_fn(left, right)

        def update(x):
            sl.add(x)
            i = sl.bisect_left(x)
            st.update(val_to_idx[x], x-(sl[i-1] if i-1 >= 0 else 0))
            if i+1 < len(sl):
                st.update(val_to_idx[sl[i+1]], sl[i+1]-x)
            
        val_to_idx = {x:i for i, x in enumerate(sorted(q[1] for q in queries if q[0] == 1))}
        st = SegmentTree(len(val_to_idx))
        sl = SortedList()
        result = []
        for q in queries:
            if q[0] == 1:
                update(q[1])
            else:
                i = sl.bisect_left(q[1])
                result.append(q[1]-(sl[i-1] if i-1 >= 0 else 0) >= q[2] or (i-1 >= 0 and st.query(0, val_to_idx[sl[i-1]]) >= q[2]))
        return result
