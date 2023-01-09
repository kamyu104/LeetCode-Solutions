# Time:  O(n + klogn)
# Space: O(n)

import heapq


# heap
class Solution(object):
    def maxKelements(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b
    
        result = 0
        max_heap = [-x for x in nums]
        heapq.heapify(max_heap)
        for _ in xrange(k):
            if not max_heap:
                break
            x = -heapq.heappop(max_heap)
            result += x
            nx = ceil_divide(x, 3)
            if not nx:
                continue
            heapq.heappush(max_heap, -nx)
        return result
  

# Time:  O(n + klogn)
# Space: O(n)
import heapq


# heap
class Solution2(object):
    def maxKelements(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b
    
        result = 0
        max_heap = [-x for x in nums]
        heapq.heapify(max_heap)
        for _ in xrange(k):
            x = -heapq.heappop(max_heap)
            result += x
            heapq.heappush(max_heap, -ceil_divide(x, 3))
        return result
  
