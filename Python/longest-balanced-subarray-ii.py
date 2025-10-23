# Time:  O(nlogn)
# Space: O(n)

# segment tree, binary search
class Solution(object):
    def longestBalanced(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        class SegmentTree(object):
            def __init__(self, N):
                self.min = [0]*(1<<((N-1).bit_length()+1))
                self.max = [0]*(1<<((N-1).bit_length()+1))
                self.base = len(self.min)>>1
                self.lazy = [0]*self.base
                
            def __apply(self, x, val):
                self.min[x] += val
                self.max[x] += val
                if x < self.base:
                    self.lazy[x] += val

            def __push(self, x):
                for h in reversed(xrange(1, x.bit_length())):
                    y = x>>h
                    if self.lazy[y]:
                        self.__apply(y<<1, self.lazy[y])
                        self.__apply((y<<1)|1, self.lazy[y])
                        self.lazy[y] = 0

            def update(self, L, R, h):  # Time: O(logN), Space: O(N)
                def pull(x):
                    while x > 1:
                        x >>= 1
                        self.min[x] = self.min[x<<1] if self.min[x<<1] < self.min[(x<<1)|1] else self.min[(x<<1)|1]
                        self.max[x] = self.max[x<<1] if self.max[x<<1] > self.max[(x<<1)|1] else self.max[(x<<1)|1]
                        if self.lazy[x]:
                            self.min[x] += self.lazy[x]
                            self.max[x] += self.lazy[x]

                L += self.base
                R += self.base
                L0, R0 = L, R
                while L <= R:
                    if L & 1:  # is right child
                        self.__apply(L, h)
                        L += 1
                    if R & 1 == 0:  # is left child
                        self.__apply(R, h)
                        R -= 1
                    L >>= 1
                    R >>= 1
                pull(L0)
                pull(R0)

            def binary_search(self, x):
                i = 1
                while not i >= self.base:
                    if self.lazy[i]:
                        self.__apply(i<<1, self.lazy[i])
                        self.__apply((i<<1)|1, self.lazy[i])
                        self.lazy[i] = 0
                    i <<= 1
                    if not self.min[i] <= x <= self.max[i]:
                        i |= 1
                return i-self.base     

        n = len(nums)+1
        st = SegmentTree(n)
        result = curr = 0
        lookup = {}
        for i, x in enumerate(nums, 1):
            d = +1 if x&1 else -1
            if x in lookup:
                st.update(lookup[x], n-1, -d)
                curr -= d
            curr += d
            lookup[x] = i
            st.update(lookup[x], n-1, d)
            l = i-st.binary_search(curr)
            if l > result:
                result = l
        return result
