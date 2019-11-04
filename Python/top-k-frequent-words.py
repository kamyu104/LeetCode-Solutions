# Time:  O(n + klogk) on average
# Space: O(n)

import collections
import heapq
from random import randint


class Solution(object):
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        counts = collections.Counter(words)
        p = []
        for key, val in counts.iteritems():
            p.append((-val, key))
        self.kthElement(p, k-1)

        result = []
        sorted_p = sorted(p[:k])
        for i in xrange(k):
            result.append(sorted_p[i][1])
        return result

    def kthElement(self, nums, k):  # O(n) on average
        def PartitionAroundPivot(left, right, pivot_idx, nums):
            pivot_value = nums[pivot_idx]
            new_pivot_idx = left
            nums[pivot_idx], nums[right] = nums[right], nums[pivot_idx]
            for i in xrange(left, right):
                if nums[i] < pivot_value:
                    nums[i], nums[new_pivot_idx] = nums[new_pivot_idx], nums[i]
                    new_pivot_idx += 1

            nums[right], nums[new_pivot_idx] = nums[new_pivot_idx], nums[right]
            return new_pivot_idx

        left, right = 0, len(nums) - 1
        while left <= right:
            pivot_idx = randint(left, right)
            new_pivot_idx = PartitionAroundPivot(left, right, pivot_idx, nums)
            if new_pivot_idx == k:
                return
            elif new_pivot_idx > k:
                right = new_pivot_idx - 1
            else:  # new_pivot_idx < k.
                left = new_pivot_idx + 1


# Time:  O(nlogk)
# Space: O(n)
# Heap Solution
class Solution2(object):
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        class MinHeapObj(object):
            def __init__(self,val):
                self.val = val
            def __lt__(self,other):
                return self.val[1] > other.val[1] if self.val[0] == other.val[0] else \
                       self.val < other.val
            def __eq__(self,other):
                return self.val == other.val
            def __str__(self):
                return str(self.val)

        counts = collections.Counter(words)
        min_heap = []
        for word, count in counts.iteritems():
            heapq.heappush(min_heap, MinHeapObj((count, word)))
            if len(min_heap) == k+1:
                heapq.heappop(min_heap)
        result = []
        while min_heap:
            result.append(heapq.heappop(min_heap).val[1])
        return result[::-1]


# Time:  O(n + klogk) ~ O(n + nlogn)
# Space: O(n)
# Bucket Sort Solution
class Solution3(object):
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        counts = collections.Counter(words)
        buckets = [[] for _ in xrange(len(words)+1)]
        for word, count in counts.iteritems():
            buckets[count].append(word)
        pairs = []
        for i in reversed(xrange(len(words))):
            for word in buckets[i]:
                pairs.append((-i, word))
            if len(pairs) >= k:
                break
        pairs.sort()
        return [pair[1] for pair in pairs[:k]]


# time: O(nlogn)
# space: O(n)

from collections import Counter


class Solution4(object):
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        counter = Counter(words)
        candidates = counter.keys()
        candidates.sort(key=lambda w: (-counter[w], w))
        return candidates[:k]
