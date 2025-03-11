# Time:  O(nlogn)
# Space: O(n)

# segment tree, binary search
class Solution(object):
    def numOfUnplacedFruits(self, fruits, baskets):
        """
        :type fruits: List[int]
        :type baskets: List[int]
        :rtype: int
        """
        class SegmentTree(object):
            def __init__(self, N,
                        build_fn=lambda _: 0,
                        query_fn=lambda x, y: y if x is None else x if y is None else max(x, y),
                        update_fn=lambda x: x):
                self.tree = [None]*(2*2**((N-1).bit_length()))
                self.base = len(self.tree)//2
                self.query_fn = query_fn
                self.update_fn = update_fn
                for i in xrange(self.base, self.base+N):
                    self.tree[i] = build_fn(i-self.base)
                for i in reversed(xrange(1, self.base)):
                    self.tree[i] = query_fn(self.tree[2*i], self.tree[2*i+1])

            def update(self, i, h):
                x = self.base+i
                self.tree[x] = self.update_fn(h)
                while x > 1:
                    x //= 2
                    self.tree[x] = self.query_fn(self.tree[x*2], self.tree[x*2+1])

            def binary_search(self, x):
                if self.tree[1] < x:
                    return -1
                i = 1
                while not i >= self.base:
                    if self.tree[2*i] >= x:
                        i = 2*i
                    else:
                        i = 2*i+1
                return i-self.base

        def build(i):
            return baskets[i]

        st = SegmentTree(len(baskets), build_fn=build)
        result = 0
        for x in fruits:
            i = st.binary_search(x)
            if i == -1:
                result += 1
            else:
                st.update(i, 0)
        return result
