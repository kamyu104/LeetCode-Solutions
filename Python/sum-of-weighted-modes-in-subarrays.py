# Time:  O(nlogk)
# Space: O(k)

import collections
from sortedcontainers import SortedList


# sorted list, two pointers, sliding window
class Solution(object):
    def modeWeight(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def add(x, diff):
            if cnt[x]:
                sl.remove((-cnt[x], x))
            cnt[x] += diff
            if cnt[x]:
                sl.add((-cnt[x], x))
            else:
                del cnt[x]
    
        cnt = collections.defaultdict(int)
        sl = SortedList()
        result = 0
        for i in xrange(len(nums)):
            add(nums[i], +1)
            if i >= k-1:
                result += -sl[0][0]*sl[0][1]
                add(nums[i-k+1], -1)
        return result


# Time:  O(nlogn)
# Space: O(n)
import collections
import heapq


# heap, two pointers, sliding window
class Solution2(object):
    def modeWeight(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        cnt = collections.defaultdict(int)
        max_heap = []
        result = 0
        for i in xrange(len(nums)):
            cnt[nums[i]] += 1
            heapq.heappush(max_heap, (-cnt[nums[i]], nums[i]))
            if i >= k-1:
                while -max_heap[0][0] != cnt[max_heap[0][1]]:
                    heapq.heappop(max_heap)
                result += -max_heap[0][0]*max_heap[0][1]
                cnt[nums[i-k+1]] -= 1
        return result
