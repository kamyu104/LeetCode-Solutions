# Time:  O(nlogn)
# Space: O(n)

import collections
import itertools
import heapq


# heap
class Solution(object):
    def mostFrequentIDs(self, nums, freq):
        """
        :type nums: List[int]
        :type freq: List[int]
        :rtype: List[int]
        """
        result = []
        cnt = collections.Counter()
        max_heap = []
        for x, f in itertools.izip(nums, freq):
            cnt[x] += f
            heapq.heappush(max_heap, (-cnt[x], x))
            while max_heap and -max_heap[0][0] != cnt[max_heap[0][1]]:
                heapq.heappop(max_heap)
            result.append(-max_heap[0][0] if max_heap else 0)
        return result


# Time:  O(nlogn)
# Space: O(n)
import collections
import itertools
from sortedcontainers import SortedList


# sorted list
class Solution2(object):
    def mostFrequentIDs(self, nums, freq):
        """
        :type nums: List[int]
        :type freq: List[int]
        :rtype: List[int]
        """
        result = []
        cnt = collections.Counter()
        cnt2 = collections.Counter()
        sl = SortedList()
        for x, f in itertools.izip(nums, freq):
            sl.discard((cnt[x], cnt2[cnt[x]]))
            cnt2[cnt[x]] -= 1
            if cnt2[cnt[x]]:
                sl.add((cnt[x], cnt2[cnt[x]]))
            cnt[x] += f
            sl.discard((cnt[x], cnt2[cnt[x]]))
            cnt2[cnt[x]] += 1
            sl.add((cnt[x], cnt2[cnt[x]]))
            result.append(sl[-1][0])
        return result
