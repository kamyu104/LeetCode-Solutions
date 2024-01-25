# Time:  O(nlogd)
# Space: O(d)

import heapq


# sliding window, heap
class Solution(object):
    def minimumCost(self, nums, k, dist):
        """
        :type nums: List[int]
        :type k: int
        :type dist: int
        :rtype: int
        """
        def get_top(heap, total):
            while abs(heap[0][1]) < i-(1+dist):
                heapq.heappop(heap)
                total[0] -= 1
            return heap[0]
            
        def lazy_delete(heap, total):
            total[0] += 1
            if total[0] <= len(heap)-total[0]:
                return
            heap[:] = [x for x in heap if abs(x[1]) > i-(1+dist)]
            heapq.heapify(heap)
            total[0] = 0

        max_heap, min_heap = [], []
        total1, total2 = [0], [0]
        mn, curr = float("inf"), 0
        for i in xrange(1, len(nums)):
            heapq.heappush(max_heap, (-nums[i], i))
            curr += nums[i]
            if i > k-1:
                x, idx = get_top(max_heap, total1)
                heapq.heappop(max_heap)
                curr -= -x
                heapq.heappush(min_heap, (-x, -idx))
            if i > 1+dist:
                x, idx = get_top(min_heap, total2)
                if (x, idx) <= (nums[i-(1+dist)], -(i-(1+dist))):
                    lazy_delete(min_heap, total2)
                else:
                    lazy_delete(max_heap, total1)
                    heapq.heappop(min_heap)
                    curr -= nums[i-(1+dist)]-x
                    heapq.heappush(max_heap, (-x, -idx))
            if i >= k-1:
                mn = min(mn, curr)
        return nums[0]+mn


# Time:  O(nlogd)
# Space: O(d)
import heapq
import collections


# sliding window, heap, freq table
class Solution2(object):
    def minimumCost(self, nums, k, dist):
        """
        :type nums: List[int]
        :type k: int
        :type dist: int
        :rtype: int
        """
        def get_top(heap, cnt, total):
            while heap[0] in cnt:
                x = heapq.heappop(heap)
                cnt[x] -= 1
                if cnt[x] == 0:
                    del cnt[x]
                total[0] -= 1
            return heap[0]

        def lazy_delete(heap, cnt, total, x):
            cnt[x] += 1
            total[0] += 1
            if total[0] <= len(heap)-total[0]:
                return
            new_heap = []
            for x in heap:
                if x not in cnt:
                    new_heap.append(x)
                    continue
                cnt[x] -= 1
                if cnt[x] == 0:
                    del cnt[x]
            total[0] = 0
            heapq.heapify(new_heap)
            heap[:] = new_heap

        max_heap, min_heap = [], []
        cnt1, cnt2 = collections.Counter(), collections.Counter()
        total1, total2 = [0], [0]
        mn, curr = float("inf"), 0
        for i in xrange(1, len(nums)):
            heapq.heappush(max_heap, -nums[i])
            curr += nums[i]
            if (len(max_heap)-total1[0]) > k-1:
                x = get_top(max_heap, cnt1, total1)
                curr -= -x
                heapq.heappush(min_heap, -heapq.heappop(max_heap))
            if (len(max_heap)-total1[0])+(len(min_heap)-total2[0]) > 1+dist:
                x = get_top(min_heap, cnt2, total2)
                if x <= nums[i-(1+dist)]:
                    lazy_delete(min_heap, cnt2, total2, nums[i-(1+dist)])
                else:
                    lazy_delete(max_heap, cnt1, total1, -nums[i-(1+dist)])
                    heapq.heappop(min_heap)
                    curr -= nums[i-(1+dist)]-x
                    heapq.heappush(max_heap, -x)
            if len(max_heap)-total1[0] == k-1:
                mn = min(mn, curr)
        return nums[0]+mn


# Time:  O(nlogd)
# Space: O(d)
from sortedcontainers import SortedList


# sliding window, sorted list
class Solution3(object):
    def minimumCost(self, nums, k, dist):
        """
        :type nums: List[int]
        :type k: int
        :type dist: int
        :rtype: int
        """
        sl1, sl2 = SortedList(), SortedList()
        mn, curr = float("inf"), 0
        for i in xrange(1, len(nums)):
            sl1.add(nums[i])
            curr += nums[i]
            if len(sl1) > k-1:
                curr -= sl1[-1]
                sl2.add(sl1.pop())
            if len(sl1)+len(sl2) > 1+dist:
                if sl2[0] <= nums[i-(1+dist)]:
                    sl2.remove(nums[i-(1+dist)])
                else:
                    sl1.remove(nums[i-(1+dist)])
                    curr -= nums[i-(1+dist)]-sl2[0]
                    sl1.add(sl2.pop(0))
            if len(sl1) == k-1:
                mn = min(mn, curr)
        return nums[0]+mn


# Time:  O(nlogd)
# Space: O(d)
from sortedcontainers import SortedList


# sliding window, sorted list
class Solution4(object):
    def minimumCost(self, nums, k, dist):
        """
        :type nums: List[int]
        :type k: int
        :type dist: int
        :rtype: int
        """
        sl = SortedList(nums[1:1+(1+dist)])
        mn = curr = sum(sl[:k-1])
        for i in xrange(1+(1+dist), len(nums)):
            sl.add(nums[i])
            curr += min(nums[i]-sl[k-1], 0)
            curr -= min(nums[i-(1+dist)]-sl[k-1], 0)
            sl.remove(nums[i-(1+dist)])
            mn = min(mn, curr)
        return nums[0]+mn
