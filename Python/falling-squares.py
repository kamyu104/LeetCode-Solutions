# Time:  O(n^2), could be improved to O(nlogn) in cpp by ordered map (bst)
# Space: O(n)

import bisect


class Solution(object):
    def fallingSquares(self, positions):
        result = []
        pos = [-1]
        heights = [0]
        maxH = 0
        for left, side in positions:
            l = bisect.bisect_right(pos, left)
            r = bisect.bisect_left(pos, left+side)
            high = max(heights[l-1:r] or [0]) + side
            pos[l:r] = [left, left+side]         # Time: O(n)
            heights[l:r] = [high, heights[r-1]]  # Time: O(n)
            maxH = max(maxH, high)
            result.append(maxH)
        return result


class SegmentTree(object):
    def __init__(self, N,
                 query_fn=min,
                 update_fn=lambda x, y: y,
                 default_val=float("inf")):
        self.N = N
        self.H = (N-1).bit_length()
        self.query_fn = query_fn
        self.update_fn = update_fn
        self.default_val = default_val
        self.tree = [default_val] * (2 * N)
        self.lazy = [None] * N

    def __apply(self, x, val):
        self.tree[x] = self.update_fn(self.tree[x], val)
        if x < self.N:
            self.lazy[x] = self.update_fn(self.lazy[x], val)

    def update(self, L, R, h):
        def pull(x):
            while x > 1:
                x //= 2
                self.tree[x] = self.query_fn(self.tree[x*2], self.tree[x*2 + 1])
                if self.lazy[x] is not None:
                    self.tree[x] = self.update_fn(self.tree[x], self.lazy[x])

        L += self.N
        R += self.N
        L0, R0 = L, R
        while L <= R:
            if L & 1:
                self.__apply(L, h)
                L += 1
            if R & 1 == 0:
                self.__apply(R, h)
                R -= 1
            L //= 2
            R //= 2
        pull(L0)
        pull(R0)

    def query(self, L, R):
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
            if L & 1:
                result = self.query_fn(result, self.tree[L])
                L += 1
            if R & 1 == 0:
                result = self.query_fn(result, self.tree[R])
                R -= 1
            L //= 2
            R //= 2
        return result
    
    def data(self):
        showList = []
        for i in xrange(self.N):
            showList.append(self.query(i, i))
        return showList


class SegmentTree2(object):
    def __init__(self, nums,
                 query_fn=min,
                 update_fn=lambda x, y: y,
                 default_val=float("inf")):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        N = len(nums)
        self.__original_length = N
        self.__tree_length = 2**(N.bit_length() + (N&(N-1) != 0))-1
        self.__query_fn = query_fn
        self.__update_fn = update_fn
        self.__default_val = default_val
        self.__tree = [default_val for _ in range(self.__tree_length)]
        self.__lazy = [None for _ in range(self.__tree_length)]
        self.__constructTree(nums, 0, self.__original_length-1, 0)

    def update(self, i, j, val):
        self.__updateTree(val, i, j, 0, self.__original_length-1, 0)

    def query(self, i, j):
        return self.__queryRange(i, j, 0, self.__original_length-1, 0)

    def __constructTree(self, nums, left, right, idx):
        if left > right:
             return
        if left == right:
            self.__tree[idx] = self.__update_fn(self.__tree[idx], nums[left])
            return 
        mid = left + (right-left)//2
        self.__constructTree(nums, left, mid, idx*2 + 1)
        self.__constructTree(nums, mid+1, right, idx*2 + 2)
        self.__tree[idx] = self.__query_fn(self.__tree[idx*2 + 1], self.__tree[idx*2 + 2])

    def __apply(self, left, right, idx, val):
        self.__tree[idx] = self.__update_fn(self.__tree[idx], val)
        if left != right:
            self.__lazy[idx*2 + 1] = self.__update_fn(self.__lazy[idx*2 + 1], val)
            self.__lazy[idx*2 + 2] = self.__update_fn(self.__lazy[idx*2 + 2], val)

    def __updateTree(self, val, range_left, range_right, left, right, idx):
        if left > right:
            return
        if self.__lazy[idx] is not None:
            self.__apply(left, right, idx, self.__lazy[idx])
            self.__lazy[idx] = None
        if range_left > right or range_right < left:
            return
        if range_left <= left and right <= range_right:
            self.__apply(left, right, idx, val)
            return
        mid = left + (right-left)//2
        self.__updateTree(val, range_left, range_right, left, mid, idx*2 + 1)
        self.__updateTree(val, range_left, range_right, mid+1, right, idx*2 + 2)
        self.__tree[idx] = self.__query_fn(self.__tree[idx*2 + 1],
                                           self.__tree[idx*2 + 2])

    def __queryRange(self, range_left, range_right, left, right, idx):
        if left > right:
            return self.__default_val
        if self.__lazy[idx] is not None:
            self.__apply(left, right, idx, self.__lazy[idx])
            self.__lazy[idx] = None
        if right < range_left or left > range_right:
            return self.__default_val
        if range_left <= left and right <= range_right:
            return self.__tree[idx]
        mid = left + (right-left)//2
        return self.__query_fn(self.__queryRange(range_left, range_right, left, mid, idx*2 + 1), 
                               self.__queryRange(range_left, range_right, mid + 1, right, idx*2 + 2))


# Time:  O(nlogn)
# Space: O(n)
# Segment Tree solution.
class Solution2(object):
    def fallingSquares(self, positions):
        index = set()
        for left, size in positions:
            index.add(left)
            index.add(left+size-1)
        index = sorted(list(index))
        tree = SegmentTree(len(index), max, max, 0)
        # tree = SegmentTree2([0]*len(index), max, max, 0)
        max_height = 0
        result = []
        for left, size in positions:
            L, R = bisect.bisect_left(index, left), bisect.bisect_left(index, left+size-1)
            h = tree.query(L, R) + size
            tree.update(L, R, h)
            max_height = max(max_height, h)
            result.append(max_height)
        return result


# Time:  O(n * sqrt(n))
# Space: O(n)
class Solution3(object):
    def fallingSquares(self, positions):
        def query(heights, left, right, B, blocks, blocks_read):
            result = 0
            while left % B and left <= right:
                result = max(result, heights[left], blocks[left//B])
                left += 1
            while right % B != B-1 and left <= right:
                result = max(result, heights[right], blocks[right//B])
                right -= 1
            while left <= right:
                result = max(result, blocks[left//B], blocks_read[left//B])
                left += B
            return result

        def update(heights, left, right, B, blocks, blocks_read, h):
            while left % B and left <= right:
                heights[left] = max(heights[left], h)
                blocks_read[left//B] = max(blocks_read[left//B], h)
                left += 1
            while right % B != B-1 and left <= right:
                heights[right] = max(heights[right], h)
                blocks_read[right//B] = max(blocks_read[right//B], h)
                right -= 1
            while left <= right:
                blocks[left//B] = max(blocks[left//B], h)
                left += B

        index = set()
        for left, size in positions:
            index.add(left)
            index.add(left+size-1)
        index = sorted(list(index))
        W = len(index)
        B = int(W**.5)
        heights = [0] * W
        blocks = [0] * (B+2)
        blocks_read = [0] * (B+2)

        max_height = 0
        result = []
        for left, size in positions:
            L, R = bisect.bisect_left(index, left), bisect.bisect_left(index, left+size-1)
            h = query(heights, L, R, B, blocks, blocks_read) + size
            update(heights, L, R, B, blocks, blocks_read, h)
            max_height = max(max_height, h)
            result.append(max_height)
        return result


# Time:  O(n^2)
# Space: O(n)
class Solution4(object):
    def fallingSquares(self, positions):
        """
        :type positions: List[List[int]]
        :rtype: List[int]
        """
        heights = [0] * len(positions)
        for i in xrange(len(positions)):
            left_i, size_i = positions[i]
            right_i = left_i + size_i
            heights[i] += size_i
            for j in xrange(i+1, len(positions)):
                left_j, size_j = positions[j]
                right_j = left_j + size_j
                if left_j < right_i and left_i < right_j:  # intersect
                    heights[j] = max(heights[j], heights[i])

        result = []
        for height in heights:
            result.append(max(result[-1], height) if result else height)
        return result

