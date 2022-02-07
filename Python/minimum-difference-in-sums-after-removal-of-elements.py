# Time:  O(nlogn)
# Space: O(n)

import heapq


# heap, prefix sum
class Solution(object):
    def minimumDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_heap = []
        for i in xrange(len(nums)//3):
            heapq.heappush(max_heap, -nums[i])
        prefix = [0]*(len(nums)//3+1)
        prefix[0] = -sum(max_heap)
        for i in xrange(len(nums)//3):
            x = -heapq.heappushpop(max_heap, -nums[i+len(nums)//3])
            prefix[i+1] = prefix[i]-x+nums[i+len(nums)//3]

        min_heap = []
        for i in reversed(xrange(len(nums)//3*2, len(nums))):
            heapq.heappush(min_heap, nums[i])
        suffix = sum(min_heap)
        result = prefix[len(nums)//3]-suffix
        for i in reversed(xrange(len(nums)//3)):
            x = heapq.heappushpop(min_heap, nums[i+len(nums)//3])
            suffix += -x+nums[i+len(nums)//3]
            result = min(result, prefix[i]-suffix)
        return result
