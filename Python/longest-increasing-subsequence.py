# Time:  O(nlogn)
# Space: O(n)

import bisect


class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        LIS = []
        def insert(target):
            left = bisect.bisect_left(LIS, target)
            # If not found, append the target.
            if left == len(LIS):
                LIS.append(target)
            else:
                LIS[left] = target
    
        for num in nums:
            insert(num)
        return len(LIS)


# Time:  O(nlogn)
# Space: O(n)
class Solution2(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        LIS = []
        def insert(target):
            left, right = 0, len(LIS) - 1
            # Find the first index "left" which satisfies LIS[left] >= target
            while left <= right:
                mid = left + (right - left) // 2
                if LIS[mid] >= target:
                    right = mid - 1
                else:
                    left = mid + 1
            # If not found, append the target.
            if left == len(LIS):
                LIS.append(target)
            else:
                LIS[left] = target

        for num in nums:
            insert(num)

        return len(LIS)


# Time:  O(nlogn)
# Space: O(n)
# bit, fenwick tree
class Solution3(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
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
    
        lookup = {x:i for i, x in enumerate(sorted(set(nums)))}
        bit = BIT(len(lookup), fn=max)
        for x in nums:
            bit.update(lookup[x], bit.query(lookup[x]-1)+1)
        return bit.query(len(lookup)-1)


# Range Maximum Query
class SegmentTree(object):  # 0-based index
    def __init__(self, N,
                 build_fn=lambda x, y: [y]*(2*x),
                 query_fn=lambda x, y: y if x is None else max(x, y),  # (lambda x, y: y if x is None else min(x, y))
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

        result = None
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
# optimized from Solution5
class Solution4(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        val_to_idx = {num:i for i, num in enumerate(sorted(set(nums)))}
        st = SegmentTree(len(val_to_idx))
        for x in nums:
            st.update(val_to_idx[x], val_to_idx[x], st.query(0, val_to_idx[x]-1)+1 if val_to_idx[x] >= 1 else 1)
        return st.query(0, len(val_to_idx)-1) if len(val_to_idx) >= 1 else 0


# Time:  O(n^2)
# Space: O(n)
# Traditional DP solution.
class Solution5(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = []  # dp[i]: the length of LIS ends with nums[i]
        for i in xrange(len(nums)):
            dp.append(1)
            for j in xrange(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp) if dp else 0

