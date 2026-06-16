# Time:  O(n^2 * logk)
# Space: O(n)

import heapq


# prefix sum, heap, dp
class Solution(object):
    def maxSum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def update(heap, total, x):
            if k == 0:
                return total
            heapq.heappush(heap, x)
            total += x
            if len(heap) == k+1:
                total -= heapq.heappop(heap)
            return total

        cnt = sum(x < 0 for x in nums)
        if cnt == len(nums):
            return max(nums)
        if cnt <= k:  # optional to boost up performance
            return sum(x for x in nums if x >= 0)
        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix[i+1] = prefix[i]+nums[i]
        result = 0
        dp = [0]*len(nums)
        for i in xrange(len(nums)):
            max_heap = [] 
            total1 = 0
            for j in xrange(i, len(nums)):
                if nums[j] < 0:
                    total1 = update(max_heap, total1, -nums[j])
                dp[j] = -total1
            min_heap = []
            total2 = 0
            for j in xrange(i):
                if nums[j] >= 0:
                    total2 = update(min_heap, total2, nums[j])
            for j in reversed(xrange(i, len(nums))):
                result = max(result, (prefix[j+1]-prefix[i])-dp[j]+total2)
                if nums[j] >= 0:
                    total2 = update(min_heap, total2, nums[j])
                    result = max(result, total2)
        return result
