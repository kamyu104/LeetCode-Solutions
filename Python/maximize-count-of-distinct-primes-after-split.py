# Time:  O(r + nlogn + qlogn), r = max(nums)
# Space: O(r + n)

from sortedcontainers import SortedList


# number theory, sorted list, segment tree
def linear_sieve_of_eratosthenes(n):  # Time: O(n), Space: O(n)
    primes = []
    spf = [-1]*(n+1)  # the smallest prime factor
    for i in xrange(2, n+1):
        if spf[i] == -1:
            spf[i] = i
            primes.append(i)
        for p in primes:
            if i*p > n or p > spf[i]:
                break
            spf[i*p] = p
    return spf


MAX_N = 10**5
SPF = linear_sieve_of_eratosthenes(MAX_N)
class Solution(object):
    def maximumCount(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        class SegmentTree(object):
            def __init__(self, N,
                         build_fn=lambda x: 0,
                         query_fn=lambda x, y: y if x is None else x if y is None else max(x, y),
                         update_fn=lambda x, y: y if x is None else x+y):
                self.tree = [None]*(1<<((N-1).bit_length()+1))
                self.base = len(self.tree)>>1
                self.lazy = [None]*self.base
                self.query_fn = query_fn
                self.update_fn = update_fn
                if build_fn is not None:
                    for i in xrange(self.base, self.base+N):
                        self.tree[i] = build_fn(i-self.base)
                    for i in reversed(xrange(1, self.base)):
                        self.tree[i] = query_fn(self.tree[i<<1], self.tree[(i<<1)+1])

            def __apply(self, x, val):
                self.tree[x] = self.update_fn(self.tree[x], val)
                if x < self.base:
                    self.lazy[x] = self.update_fn(self.lazy[x], val)

            def __push(self, x):
                for h in reversed(xrange(1, x.bit_length())):
                    y = x>>h
                    if self.lazy[y] is not None:
                        self.__apply(y<<1, self.lazy[y])
                        self.__apply((y<<1)+1, self.lazy[y])
                        self.lazy[y] = None

            def update(self, L, R, h):  # Time: O(logN), Space: O(N)
                def pull(x):
                    while x > 1:
                        x >>= 1
                        self.tree[x] = self.query_fn(self.tree[x<<1], self.tree[(x<<1)+1])
                        if self.lazy[x] is not None:
                            self.tree[x] = self.update_fn(self.tree[x], self.lazy[x])

                L += self.base
                R += self.base
                # self.__push(L)  # enable if range assignment
                # self.__push(R)  # enable if range assignment
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

            def query(self, L, R):
                if L > R:
                    return None
                L += self.base
                R += self.base
                self.__push(L)
                self.__push(R)
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

        def add(i, d):
            x = nums[i]
            if SPF[x] != x:
                return
            if d == 1:
                lookup[x].add(i)
            if len(lookup[x]) == 1:
                st.update(0, len(nums)-2, d)
            elif i == lookup[x][0]:
                st.update(i, lookup[x][1]-1, d)
            elif i == lookup[x][-1]:
                st.update(lookup[x][-2], i-1, d)
            if d == -1:
                lookup[x].remove(i)

        lookup = collections.defaultdict(SortedList)
        st = SegmentTree(len(nums)-1)
        for i in xrange(len(nums)):
            add(i, +1)
        result = [0]*len(queries)
        for i, (idx, x) in enumerate(queries):
            if nums[idx] != x:
                add(idx, -1)
                nums[idx] = x
                add(idx, +1)
            result[i] = st.tree[1]  # st.query(0, len(nums)-2)
        return result
