# Time:  O(n + klogk)
# Space: O(k)

import random


class Solution(object):
    def minDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def nth_element(nums, left, n, right, compare=lambda a, b: a < b):
            def partition_around_pivot(left, right, pivot_idx, nums, compare):
                new_pivot_idx = left
                nums[pivot_idx], nums[right] = nums[right], nums[pivot_idx]
                for i in xrange(left, right):
                    if compare(nums[i], nums[right]):
                        nums[i], nums[new_pivot_idx] = nums[new_pivot_idx], nums[i]
                        new_pivot_idx += 1

                nums[right], nums[new_pivot_idx] = nums[new_pivot_idx], nums[right]
                return new_pivot_idx

            while left <= right:
                pivot_idx = random.randint(left, right)
                new_pivot_idx = partition_around_pivot(left, right, pivot_idx, nums, compare)
                if new_pivot_idx == n:
                    return
                elif new_pivot_idx > n:
                    right = new_pivot_idx - 1
                else:  # new_pivot_idx < n
                    left = new_pivot_idx + 1

        k = 4
        if len(nums) <= k:
            return 0
        nth_element(nums, 0, k, len(nums)-1)
        nums[:k] = sorted(nums[:k])
        nth_element(nums, k, max(k, len(nums)-k), len(nums)-1)
        nums[-k:] = sorted(nums[-k:])
        return min(nums[-k+i]-nums[i] for i in xrange(k))
