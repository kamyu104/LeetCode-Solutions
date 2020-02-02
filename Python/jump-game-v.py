# Time:  O(nlogn)
# Space: O(n)

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


class Solution(object):
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


# Time:  O(max(nlogn, n * d))
# Space: O(n) 
class Solution2(object):
    def maxJumps(self, arr, d):
        """
        :type arr: List[int]
        :type d: int
        :rtype: int
        """
        dp = [1]*len(arr)
        for a, i in sorted([a, i] for i, a in enumerate(arr)):
            for di in [-1, 1]:
                for j in xrange(i+di, i+di + d*di, di):
                    if not (0 <= j < len(arr) and arr[i] > arr[j]):
                        break
                    dp[i] = max(dp[i], dp[j]+1)
        return max(dp)


# Time:  O(n * d)
# Space: O(n) 
import itertools


class Solution3(object):
    def maxJumps(self, arr, d):
        """
        :type arr: List[int]
        :type d: int
        :rtype: int
        """
        def dp(arr, i, lookup):
            if lookup[i]:
                return lookup[i]
            lookup[i] = 1
            for di in [-1, 1]:
                for j in xrange(i+di, i+di + d*di, di):
                    if not (0 <= j < len(arr) and arr[i] > arr[j]):
                        break
                    lookup[i] = max(lookup[i], dp(arr, j, lookup)+1)
            return lookup[i]

        lookup = [0]*len(arr)
        return max(itertools.imap(lambda x: dp(arr, x, lookup), xrange(len(arr))))
