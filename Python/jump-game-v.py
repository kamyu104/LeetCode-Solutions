# Time:  O(n)
# Space: O(n)

import collections
import itertools


# sliding window + top-down dp
class Solution(object):
    def maxJumps(self, arr, d):
        """
        :type arr: List[int]
        :type d: int
        :rtype: int
        """
        def dp(arr, d, i, left, right, lookup):
            if lookup[i]:
                return lookup[i]
            lookup[i] = 1
            for j in itertools.chain(left[i], right[i]):
                # each dp[j] will be visited at most twice 
                lookup[i] = max(lookup[i], dp(arr, d, j, left, right, lookup)+1)
            return lookup[i]

        left, decreasing_dq = [[] for _ in xrange(len(arr))], collections.deque()
        for i in xrange(len(arr)):
            if decreasing_dq and i - decreasing_dq[0] == d+1:
                decreasing_dq.popleft()
            while decreasing_dq and arr[decreasing_dq[-1]] < arr[i]:
                if left[i] and arr[left[i][-1]] != arr[decreasing_dq[-1]]:
                    left[i] = []
                left[i].append(decreasing_dq.pop())
            decreasing_dq.append(i)
        right, decreasing_dq = [[] for _ in xrange(len(arr))], collections.deque()
        for i in reversed(xrange(len(arr))):
            if decreasing_dq and decreasing_dq[0] - i == d+1:
                decreasing_dq.popleft()
            while decreasing_dq and arr[decreasing_dq[-1]] < arr[i]:
                if right[i] and arr[right[i][-1]] != arr[decreasing_dq[-1]]:
                    right[i] = []
                right[i].append(decreasing_dq.pop())
            decreasing_dq.append(i)

        lookup = [0]*len(arr)
        return max(itertools.imap(lambda x: dp(arr, d, x, left, right, lookup), xrange(len(arr))))


# Time:  O(nlogn)
# Space: O(n)
# mono stack + bottom-up dp
class Solution2(object):
    def maxJumps(self, arr, d):
        """
        :type arr: List[int]
        :type d: int
        :rtype: int
        """
        left, decreasing_stk = [[] for _ in xrange(len(arr))], []
        for i in xrange(len(arr)):
            while decreasing_stk and arr[decreasing_stk[-1]] < arr[i]:
                if i - decreasing_stk[-1] <= d:
                    if left[i] and arr[left[i][-1]] != arr[decreasing_stk[-1]]:
                        left[i] = []
                    left[i].append(decreasing_stk[-1])
                decreasing_stk.pop()
            decreasing_stk.append(i)
        right, decreasing_stk = [[] for _ in xrange(len(arr))], []
        for i in reversed(xrange(len(arr))):
            while decreasing_stk and arr[decreasing_stk[-1]] < arr[i]:
                if decreasing_stk[-1] - i <= d:
                    if right[i] and arr[right[i][-1]] != arr[decreasing_stk[-1]]:
                        right[i] = []
                    right[i].append(decreasing_stk[-1])
                decreasing_stk.pop()
            decreasing_stk.append(i)

        dp = [0]*len(arr)
        for a, i in sorted([a, i] for i, a in enumerate(arr)):
            dp[i] = 1
            for j in itertools.chain(left[i], right[i]):
                # each dp[j] will be visited at most twice 
                dp[i] = max(dp[i], dp[j]+1)
        return max(dp)


# Template:
# https://github.com/kamyu104/FacebookHackerCup-2018/blob/master/Final%20Round/the_claw.py
class SegmentTree(object):
    def __init__(self, N,
                 build_fn=lambda x, y: [y]*(2*x),
                 query_fn=max,
                 update_fn=lambda x, y: y,
                 default_val=0):
        self.N = N
        self.H = (N-1).bit_length()
        self.query_fn = query_fn
        self.update_fn = update_fn
        self.default_val = default_val
        self.tree = build_fn(N, default_val)
        self.lazy = [None]*N

    def __apply(self, x, val):
        self.tree[x] = self.update_fn(self.tree[x], val)
        if x < self.N:
            self.lazy[x] = self.update_fn(self.lazy[x], val)

    def update(self, L, R, h):  # Time: O(logN), Space: O(N)
        def pull(x):
            while x > 1:
                x //= 2
                self.tree[x] = self.query_fn(self.tree[x*2], self.tree[x*2+1])
                if self.lazy[x] is not None:
                    self.tree[x] = self.update_fn(self.tree[x], self.lazy[x])
        L += self.N
        R += self.N
        L0, R0 = L, R
        while L <= R:
            if L & 1:  # is right child
                self.__apply(L, h)
                L += 1
            if R & 1 == 0:  # is left child
                self.__apply(R, h)
                R -= 1
            L //= 2
            R //= 2
        pull(L0)
        pull(R0)

    def query(self, L, R):  # Time: O(logN), Space: O(N)
        def push(x):
            n = 2**self.H
            while n != 1:
                y = x // n
                if self.lazy[y] is not None:
                    self.__apply(y*2, self.lazy[y])
                    self.__apply(y*2 + 1, self.lazy[y])
                    self.lazy[y] = None
                n //= 2

        result = self.default_val
        if L > R:
            return result

        L += self.N
        R += self.N
        push(L)
        push(R)
        while L <= R:
            if L & 1:  # is right child
                result = self.query_fn(result, self.tree[L])
                L += 1
            if R & 1 == 0:  # is left child
                result = self.query_fn(result, self.tree[R])
                R -= 1
            L //= 2
            R //= 2
        return result
    
    def __str__(self):
        showList = []
        for i in xrange(self.N):
            showList.append(self.query(i, i))
        return ",".join(map(str, showList))


# Time:  O(nlogn)
# Space: O(n)
# mono stack + bottom-up dp + segment tree
class Solution3(object):
    def maxJumps(self, arr, d):
        """
        :type arr: List[int]
        :type d: int
        :rtype: int
        """
        left, decreasing_stk = range(len(arr)), []
        for i in xrange(len(arr)):
            while decreasing_stk and arr[decreasing_stk[-1]] < arr[i]:
                if i - decreasing_stk[-1] <= d:
                    left[i] = decreasing_stk[-1]
                decreasing_stk.pop()
            decreasing_stk.append(i)
        right, decreasing_stk = range(len(arr)), []
        for i in reversed(xrange(len(arr))):
            while decreasing_stk and arr[decreasing_stk[-1]] < arr[i]:
                if decreasing_stk[-1] - i <= d:
                    right[i] = decreasing_stk[-1]
                decreasing_stk.pop()
            decreasing_stk.append(i)

        segment_tree = SegmentTree(len(arr))
        for _, i in sorted([x, i] for i, x in enumerate(arr)):
            segment_tree.update(i, i, segment_tree.query(left[i], right[i]) + 1)
        return segment_tree.query(0, len(arr)-1)
