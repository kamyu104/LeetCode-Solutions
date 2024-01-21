# Time:  O(n)
# Space: O(1)

import random


# array, quick select
class Solution(object):
    def minimumCost(self, nums):
        """
        :type nums: List[int]
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

        nth_element(nums, 1+(2-1), 1)
        return nums[0]+nums[1]+nums[2]


# Time:  O(n)
# Space: O(1)
# array
class Solution2(object):
    def minimumCost(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def topk(a, k):
            result = [float("inf")]*k
            for x in a:
                for i in xrange(len(result)):
                    if x < result[i]:
                        result[i], x = x, result[i]
            return result

        return nums[0]+sum(topk((nums[i] for i in xrange(1, len(nums))), 2))
