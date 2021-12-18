# Time:  O(n) on average
# Space: O(1)

import random


# quick select solution
class Solution(object):
    def largestEvenSum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def nth_element(nums, n, compare=lambda a, b: a < b):
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

            left, right = 0, len(nums)-1
            while left <= right:
                pivot_idx = random.randint(left, right)
                pivot_left, pivot_right = tri_partition(nums, left, right, nums[pivot_idx], compare)
                if pivot_left <= n <= pivot_right:
                    return
                elif pivot_left > n:
                    right = pivot_left-1
                else:  # pivot_right < n.
                    left = pivot_right+1

        nth_element(nums, k-1, compare=lambda a, b: a > b)
        total = sum(nums[i] for i in xrange(k))
        if total%2 == 0:
            return total
        min_k = [float("inf")]*2
        for i in xrange(k):
            min_k[nums[i]%2] = min(min_k[nums[i]%2], nums[i])
        result = -1
        for i in xrange(k, len(nums)):
            result = max(result, total-min_k[not (nums[i]%2)]+nums[i])
        return result
