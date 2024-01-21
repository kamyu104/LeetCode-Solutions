# Time:  O(nlogd)
# Space: O(d)

from sortedcontainers import SortedList


# sliding window, sorted list
class Solution(object):
    def minimumCost(self, nums, k, dist):
        """
        :type nums: List[int]
        :type k: int
        :type dist: int
        :rtype: int
        """
        sl = SortedList(nums[1:1+(1+dist)])
        curr = mn = sum(sl[:k-1])
        for i in xrange(1+(1+dist), len(nums)):
            sl.add(nums[i])
            curr += min(nums[i]-sl[k-1], 0)
            curr -= min(nums[i-(1+dist)]-sl[k-1], 0)
            sl.remove(nums[i-(1+dist)])
            mn = min(mn, curr)
        return nums[0]+mn


# Time:  O(nlogd)
# Space: O(d)
from sortedcontainers import SortedList


# sliding window, sorted list
class Solution2(object):
    def minimumCost(self, nums, k, dist):
        """
        :type nums: List[int]
        :type k: int
        :type dist: int
        :rtype: int
        """
        sl1, sl2 = SortedList(), SortedList()
        curr, mn = 0, float("inf")
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
import heapq


# sliding window, heap
class Solution3(object):
    def minimumCost(self, nums, k, dist):
        """
        :type nums: List[int]
        :type k: int
        :type dist: int
        :rtype: int
        """
        max_heap, min_heap = [], []
        total1 = total2 = 0
        curr, mn = 0, float("inf")
        for i in xrange(1, len(nums)):
            heapq.heappush(max_heap, (-nums[i], i))
            curr += nums[i]
            if (len(max_heap)-total1) > k-1:
                while max_heap[0][1] < i-(1+dist):
                    heapq.heappop(max_heap)
                    total1 -= 1
                assert(total1 >= 0)
                x, idx = heapq.heappop(max_heap)
                curr -= -x
                heapq.heappush(min_heap, (-x, -idx))
            if (len(max_heap)-total1)+(len(min_heap)-total2) > 1+dist:
                while -min_heap[0][1] < i-(1+dist):
                    heapq.heappop(min_heap)
                    total2 -= 1
                if min_heap[0] <= (nums[i-(1+dist)], -(i-(1+dist))):
                    total2 += 1
                else:
                    total1 += 1
                    x, idx = heapq.heappop(min_heap)
                    curr -= nums[i-(1+dist)]-x
                    heapq.heappush(max_heap, (-x, -idx))
            if len(max_heap)-total1 == k-1:
                mn = min(mn, curr)
        return nums[0]+mn


# Time:  O(nlogd)
# Space: O(d)
import heapq
import collections


# sliding window, heap
class Solution4(object):
    def minimumCost(self, nums, k, dist):
        """
        :type nums: List[int]
        :type k: int
        :type dist: int
        :rtype: int
        """
        max_heap, min_heap = [], []
        cnt1, cnt2 = collections.Counter(), collections.Counter()
        total1 = total2 = 0
        curr, mn = 0, float("inf")
        for i in xrange(1, len(nums)):
            heapq.heappush(max_heap, -nums[i])
            curr += nums[i]
            if (len(max_heap)-total1) > k-1:
                while -max_heap[0] in cnt1:
                    x = -heapq.heappop(max_heap)
                    cnt1[x] -= 1
                    if cnt1[x] == 0:
                        del cnt1[x]
                    total1 -= 1
                curr -= -max_heap[0]
                heapq.heappush(min_heap, -heapq.heappop(max_heap))
            if (len(max_heap)-total1)+(len(min_heap)-total2) > 1+dist:
                while min_heap[0] in cnt2:
                    x = heapq.heappop(min_heap)
                    cnt2[x] -= 1
                    if cnt2[x] == 0:
                        del cnt2[x]
                    total2 -= 1
                if min_heap[0] <= nums[i-(1+dist)]:
                    cnt2[nums[i-(1+dist)]] += 1
                    total2 += 1
                else:
                    cnt1[nums[i-(1+dist)]] += 1
                    total1 += 1
                    curr -= nums[i-(1+dist)]-min_heap[0]
                    heapq.heappush(max_heap, -heapq.heappop(min_heap))
            if len(max_heap)-total1 == k-1:
                mn = min(mn, curr)
        return nums[0]+mn
