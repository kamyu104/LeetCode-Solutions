# Time:  O(nlogn * logr), r is the sum of range x size and range y size
# Space: O(n)

# Range Maximum Query
class SegmentTree(object):  # 0-based index
    def __init__(self, N,
                 build_fn=lambda x, y: [y]*(2*x),
                 query_fn=lambda x, y: y if x is None else max(x, y),
                 update_fn=lambda x, y: y if x is None else x+y,
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


# competitive programming solution
class Solution(object):
    def minDayskVariants(self, points, k):
        """
        :type points: List[List[int]]
        :type k: int
        :rtype: int
        """
        def add_rec(rec, intervals):
            x0, y0, x1, y1 = rec
            # add [y0, y1] by 1 in [x0, x1+1)
            intervals.append([[x0,   +1], [y0, y1]])
            intervals.append([[x1+1, -1], [y0, y1]])

        def check(points, k, l):  # Time: O(nlogn), Space: O(n)
            intervals = []
            y_set = set()
            for x, y in points:
                add_rec([x-l, y-l, x+l, y+l], intervals)
                y_set.add(y-l)
                y_set.add(y+l)
            intervals.sort()
            y_to_idx = {y:i for i, y in enumerate(sorted(y_set))}  # coordinate compression
            st = SegmentTree(len(y_to_idx))
            for [_, v], [y0, y1] in intervals:  # line sweep
                st.update(y_to_idx[y0], y_to_idx[y1], v)
                if st.query(0, len(y_to_idx)-1) >= k:
                    return True
            return False
                
        points = [[x+y, x-y] for x, y in points]  # rotate
        min_x = min(points)[0]
        max_x = max(points)[0]
        min_y = min(points, key=lambda x: x[1])[1]
        max_y = max(points, key=lambda x: x[1])[1]
        left, right = 0, ((max_x-min_x)+(max_y-min_y)+1)//2
        while left <= right:
            mid = left + (right-left)//2
            if check(points, k, mid):
                right = mid-1
            else:
                left = mid+1
        return left


# Time:  O(n^2 * logr), r is the sum of range x size and range y size
# Space: O(n)
import collections


# interview solution
class Solution2(object):
    def minDayskVariants(self, points, k):
        """
        :type points: List[List[int]]
        :type k: int
        :rtype: int
        """
        def add_rec(rec, intervals):
            x0, y0, x1, y1 = rec
            # add [y0, y1+1) by 1 in [x0, x1+1)
            intervals[x0][y0] += 1
            intervals[x0][y1+1] -= 1
            intervals[x1+1][y0] -= 1
            intervals[x1+1][y1+1] += 1

        def check(points, k, l):  # Time: O(n^2), Space: O(n)
            intervals = collections.defaultdict(lambda:collections.defaultdict(int))
            y_set = set()
            for x, y in points:
                add_rec([x-l, y-l, x+l, y+l], intervals)
                y_set.add(y-l)
                y_set.add(y+l+1)
            sorted_y = sorted(y_set)
            sorted_x = sorted(intervals.iterkeys())
            count = collections.Counter()
            for x in sorted_x:  # line sweep
                for y, c in intervals[x].iteritems():
                    count[y] += c
                cnt = 0
                for y in sorted_y:
                    cnt += count[y]
                    if cnt >= k:
                        return True
            return False
                
        points = [[x+y, x-y] for x, y in points]  # rotate
        min_x = min(points)[0]
        max_x = max(points)[0]
        min_y = min(points, key=lambda x: x[1])[1]
        max_y = max(points, key=lambda x: x[1])[1]
        left, right = 0, ((max_x-min_x)+(max_y-min_y)+1)//2
        while left <= right:
            mid = left + (right-left)//2
            if check(points, k, mid):
                right = mid-1
            else:
                left = mid+1
        return left
