# Time:  O(nlogr)
# Space: O(n)

import random


# bitmasks, greedy, quick select
class Solution(object):
    def maximumAND(self, nums, k, m):
        """
        :type nums: List[int]
        :type k: int
        :type m: int
        :rtype: int
        """
        def nth_element(nums, n, left=0, compare=lambda a, b: a < b):
            def tri_partition(nums, left, right, target, compare):
                mid = left
                while mid <= right:
                    if nums[mid] == target:
                        mid += 1
                    elif compare(nums[mid], target):
                        nums[left], nums[mid] = nums[mid], nums[left]
                        left += 1
                        mid += 1
                    else:
                        nums[mid], nums[right] = nums[right], nums[mid]
                        right -= 1
                return left, right
            
            right = len(nums)-1
            while left <= right:
                pivot_idx = random.randint(left, right)
                pivot_left, pivot_right = tri_partition(nums, left, right, nums[pivot_idx], compare)
                if pivot_left <= n <= pivot_right:
                    return
                elif pivot_left > n:
                    right = pivot_left-1
                else:  # pivot_right < n.
                    left = pivot_right+1

        result = 0
        for i in reversed(xrange((max(nums)+k).bit_length())):
            target = result|(1<<i)
            costs = []
            for x in nums:
                l = (target&~x).bit_length()
                mask = (1<<l)-1
                costs.append((target&mask)-(x&mask))
            nth_element(costs, m-1)
            if sum(costs[i] for i in xrange(m)) <= k:
                result |= 1<<i
        return result


# Time:  O(nlogn * logr)
# Space: O(n)
# bitmasks, greedy, sort
class Solution2(object):
    def maximumAND(self, nums, k, m):
        """
        :type nums: List[int]
        :type k: int
        :type m: int
        :rtype: int
        """
        result = 0
        for i in reversed(xrange((max(nums)+k).bit_length())):
            target = result|(1<<i)
            costs = []
            for x in nums:
                l = (target&~x).bit_length()
                mask = (1<<l)-1
                costs.append((target&mask)-(x&mask))
            costs.sort()
            if sum(costs[i] for i in xrange(m)) <= k:
                result |= 1<<i
        return result
