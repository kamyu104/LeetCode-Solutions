# Time:  O(nlogn)
# Space: O(n)

import collections
import heapq


class Solution(object):
    def medianSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[float]
        """
        min_heap, max_heap = [], []
        for i in xrange(k):
            if k%2:
                heapq.heappush(min_heap, -heapq.heappushpop(max_heap, -nums[i]))
            else:
                heapq.heappush(max_heap, -heapq.heappushpop(min_heap, nums[i]))
        result = [float(min_heap[0])] if k%2 else [(min_heap[0]-max_heap[0])/2.0]
        to_remove = collections.defaultdict(int)
        for i in xrange(k, len(nums)):
            heapq.heappush(max_heap, -heapq.heappushpop(min_heap, nums[i]))
            if nums[i-k] > -max_heap[0]:
                heapq.heappush(min_heap, -heapq.heappop(max_heap))
            to_remove[nums[i-k]] += 1
            while max_heap and -max_heap[0] in to_remove:  # lazy delete
                to_remove[-max_heap[0]] -= 1
                if not to_remove[-max_heap[0]]:
                    del to_remove[-max_heap[0]]
                heapq.heappop(max_heap)
            while min_heap[0] in to_remove:
                to_remove[min_heap[0]] -= 1
                if not to_remove[min_heap[0]]:
                    del to_remove[min_heap[0]]
                heapq.heappop(min_heap)
            if k%2:
                result.append(float(min_heap[0]))
            else:
                result.append((min_heap[0]+(-max_heap[0]))/2.0)
        return result
