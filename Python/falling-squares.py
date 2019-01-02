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
    def __init__(self, N, update_fn, query_fn):
        self.N = N
        self.H = 1
        while (1 << self.H) < N:
            self.H += 1

        self.update_fn = update_fn
        self.query_fn = query_fn
        self.tree = [0] * (2 * N)
        self.lazy = [0] * N

    def __apply(self, x, val):
        self.tree[x] = self.update_fn(self.tree[x], val)
        if x < self.N:
            self.lazy[x] = self.update_fn(self.lazy[x], val)

    def __pull(self, x):
        while x > 1:
            x /= 2
            self.tree[x] = self.query_fn(self.tree[x*2], self.tree[x*2 + 1])
            self.tree[x] = self.update_fn(self.tree[x], self.lazy[x])

    def __push(self, x):
        for h in xrange(self.H, 0, -1):
            y = x >> h
            if self.lazy[y]:
                self.__apply(y*2, self.lazy[y])
                self.__apply(y*2 + 1, self.lazy[y])
                self.lazy[y] = 0

    def update(self, L, R, h):
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
            L /= 2
            R /= 2
        self.__pull(L0)
        self.__pull(R0)

    def query(self, L, R):
        L += self.N
        R += self.N
        self.__push(L)
        self.__push(R)
        result = 0
        while L <= R:
            if L & 1:
                result = self.query_fn(result, self.tree[L])
                L += 1
            if R & 1 == 0:
                result = self.query_fn(result, self.tree[R])
                R -= 1
            L /= 2
            R /= 2
        return result


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
        tree = SegmentTree(len(index), max, max)
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

