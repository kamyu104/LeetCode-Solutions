# Time:  O(nlogn)
# Space: O(n)

import heapq


# simulation, heap
class Solution(object):
    def minOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result = 0
        heapq.heapify(nums)
        while nums:
            if nums[0] >= k:
                break
            mn1 = heapq.heappop(nums)
            mn2 = heapq.heappop(nums)
            heapq.heappush(nums, 2*mn1+mn2)
            result += 1
        return result
