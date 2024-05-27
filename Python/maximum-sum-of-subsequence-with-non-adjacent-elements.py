# Time:  O(n + qlogn)
# Space: O(n)

# segment tree
class Solution(object):
    def maximumSumSubsequence(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: int
        """
        MOD = 10**9+7
        L0R0, L1R0, L0R1, L1R1 = range(4)
        # Template:
        # https://github.com/kamyu104/LeetCode-Solutions/blob/master/Python/block-placement-queries.py
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
        
        def build(i):
            return [max(nums[i], 0), 0, 0, 0]
        
        def query(x, y):
            if x is None:
                return y
            if y is None:
                return x
            return [max(x[L0R1]+y[L1R0], x[L0R0]+y[L1R0], x[L0R1]+y[L0R0]),
                    max(x[L1R1]+y[L1R0], x[L1R0]+y[L1R0], x[L1R1]+y[L0R0]),
                    max(x[L0R1]+y[L1R1], x[L0R0]+y[L1R1], x[L0R1]+y[L0R1]),
                    max(x[L1R1]+y[L1R1], x[L1R0]+y[L1R1], x[L1R1]+y[L0R1])]

        st = SegmentTree(len(nums), build_fn=build, query_fn=query)
        result = 0
        for i, x in queries:
            st.update(i, [max(x, 0), 0, 0, 0])
            result = (result+max(st.tree[1]))%MOD
        return result
