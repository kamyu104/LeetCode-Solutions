# Time:  O(n + klogn)
# Space: O(n)

import heapq


# greedy, heap, doubly linked list
class Solution(object):
    def minOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if 2*k > len(nums):
            return -1
        if not k:
            return 0
        lookup = [False]*len(nums)
        left = [(i-1)%len(nums) for i in xrange(len(nums))]
        right = [(i+1)%len(nums) for i in xrange(len(nums))]
        cost = [max((max(nums[left[i]], nums[right[i]])+1)-nums[i], 0) for i in xrange(len(nums))]
        min_heap = [(cost[i], i) for i in xrange(len(nums))]
        heapq.heapify(min_heap)
        result = 0
        while min_heap:
            c, i = heapq.heappop(min_heap)
            if lookup[i]:
                continue
            result += c
            k -= 1
            if not k:
                break
            cost[i] = cost[left[i]]+cost[right[i]]-cost[i]
            heapq.heappush(min_heap, (cost[i], i))
            lookup[left[i]] = lookup[right[i]] = True
            left[i] = left[left[i]]
            right[i] = right[right[i]]
            right[left[i]] = left[right[i]] = i
        return result
