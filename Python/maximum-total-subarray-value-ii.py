# Time:  O((n + k) * logn)
# Space: O(k)

import heapq


# heap, sort, two pointers
class Solution(object):
    def maxTotalValue(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def nxt(left, right, i, j):
            while not (left <= idxs[i] <= right):
                i += 1
            while not (left <= idxs[j] <= right):
                j -= 1
            return (i, j)
            
        idxs = range(len(nums))
        idxs.sort(key=lambda x: (nums[x], x))
        lookup = {(0, len(nums)-1):(0, len(idxs)-1)}
        max_heap = [(-(nums[idxs[len(idxs)-1]]-nums[idxs[0]]), (0, len(idxs)-1))]
        result = 0
        while k:
            v, (l, r) = heapq.heappop(max_heap)
            i, j = lookup[(l, r)]
            nl, nr = min(idxs[i], idxs[j]), max(idxs[i], idxs[j])
            c = min((nl-l+1)*(r-nr+1), k)
            k -= c
            result += c*(-v)
            if nl+1 <= r and (nl+1, r) not in lookup:
                lookup[(nl+1, r)] = (ni, nj) = nxt(nl+1, r, i, j)
                heapq.heappush(max_heap, (-(nums[idxs[nj]]-nums[idxs[ni]]), (nl+1, r)))
            if l <= nr-1 and (l, nr-1) not in lookup:
                lookup[(l, nr-1)] = (ni, nj) = nxt(l, nr-1, i, j)
                heapq.heappush(max_heap, (-(nums[idxs[nj]]-nums[idxs[ni]]), (l, nr-1)))
        return result


# Time:  O((n + k) * logn)
# Space: O(nlogn)
import heapq


# heap, rmq, sparse table
class Solution2(object):
    def maxTotalValue(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # RMQ - Sparse Table
        # Template: https://github.com/kamyu104/GoogleCodeJam-Farewell-Rounds/blob/main/Round%20D/genetic_sequences2.py3
        # Time:  ctor:  O(NlogN) * O(fn)
        #        query: O(fn)
        # Space: O(NlogN)
        class SparseTable(object):
            def __init__(self, arr, fn):
                self.fn = fn
                self.bit_length = [0]
                n = len(arr)
                k = n.bit_length()-1  # log2_floor(n)
                for i in xrange(k+1):
                    self.bit_length.extend(i+1 for _ in xrange(min(1<<i, (n+1)-len(self.bit_length))))
                self.st = [[0]*n for _ in xrange(k+1)]
                self.st[0] = arr[:]
                for i in xrange(1, k+1):  # Time: O(NlogN) * O(fn)
                    for j in xrange((n-(1<<i))+1):
                        self.st[i][j] = fn(self.st[i-1][j], self.st[i-1][j+(1<<(i-1))])
        
            def query(self, L, R):  # Time: O(fn)
                i = self.bit_length[R-L+1]-1  # log2_floor(R-L+1)
                return self.fn(self.st[i][L], self.st[i][R-(1<<i)+1])
        
        rmq_min = SparseTable(nums, min)
        rmq_max = SparseTable(nums, max)
        max_heap = [(-(rmq_max.query(i, len(nums)-1)-rmq_min.query(i, len(nums)-1)), (i, len(nums)-1)) for i in xrange(len(nums))]
        heapq.heapify(max_heap)
        result = 0
        for _ in xrange(k):
            v, (i, j) = heappop(max_heap)
            result += -v
            if i <= j-1:
                heapq.heappush(max_heap, (-(rmq_max.query(i, j-1)-rmq_min.query(i, j-1)), (i, j-1)))
        return result
