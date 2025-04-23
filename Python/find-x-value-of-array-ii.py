# Time:  O(n * k + q * k * logn)
# Space: O(n * k)

# segment tree
class Solution(object):
    def resultArray(self, nums, k, queries):
        """
        :type nums: List[int]
        :type k: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
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
            x = nums[i]%k
            cnt = [0]*(k+1)
            cnt[x] = 1
            cnt[-1] = x
            return cnt

        def update(x):
            x %= k
            cnt = [0]*(k+1)
            cnt[x] = 1
            cnt[-1] = x
            return cnt
            
        def query(x, y):
            if x is None:
                return y
            if y is None:
                return x
            cnt = x[:]
            for i in xrange(k):
                cnt[x[-1]*i%k] += y[i]
            cnt[-1] = x[-1]*y[-1]%k
            return cnt
        
        st = SegmentTree(len(nums), build_fn=build, update_fn=update, query_fn=query)
        result = [0]*len(queries)
        for idx, (i, v, s, x) in enumerate(queries):
            st.update(i, v)
            result[idx] = st.query(s, len(nums)-1)[x]
        return result
