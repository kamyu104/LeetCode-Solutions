# Time:  O(nlogk)
# Space: O(k)

from sortedcontainers import SortedList


class Solution(object):
    def medianSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[float]
        """
        sl = SortedList(float(nums[i])for i in xrange(k))
        result = [(sl[k//2]+sl[k//2-(1-k%2)])/2]
        for i in xrange(k, len(nums)):
            sl.add(float(nums[i]))
            sl.remove(nums[i-k])
            result.append((sl[k//2]+sl[k//2-(1-k%2)])/2)
        return result


# Time:  O(nlogk)
# Space: O(k)
import collections
import heapq


class Solution2(object):
    def medianSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[float]
        """
        def rebuild_heap(heap, to_remove, sign):  # Time: O(k), Space: O(k)
            result = []
            for x in heap:
                if sign*x not in to_remove:
                    result.append(x)
                    continue
                to_remove[sign*x] -= 1
                if not to_remove[sign*x]:
                    del to_remove[sign*x]
            heap[:] = result
            heapify(heap)

        min_heap, max_heap = [], []
        for i in xrange(k):
            if i%2 == 0:
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
            if len(min_heap)+len(max_heap) > 2*k:
                rebuild_heap(max_heap, to_remove, -1)
                rebuild_heap(min_heap, to_remove, 1)
            result.append(float(min_heap[0]) if k%2 else (min_heap[0]-max_heap[0])/2.0)
        return result


# Time:  O(nlogn) due to lazy delete
# Space: O(n)
import collections
import heapq


class Solution3(object):
    def medianSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[float]
        """
        min_heap, max_heap = [], []
        for i in xrange(k):
            if i%2 == 0:
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
            result.append(float(min_heap[0]) if k%2 else (min_heap[0]-max_heap[0])/2.0)
        return result
