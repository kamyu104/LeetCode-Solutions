# Time:  O(n)
# Space: O(1)

import random


# quick select, greedy
class Solution(object):
    def minOperationsToMakeMedianK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
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
    
        nth_element(nums, len(nums)//2)
        return (sum(max(nums[i]-k, 0) for i in xrange(len(nums)//2+1))+
                sum(max(k-nums[i], 0) for i in xrange(len(nums)//2, len(nums))))


# Time:  O(nlogn)
# Space: O(1)
# sort, greedy
class Solution2(object):
    def minOperationsToMakeMedianK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        return (sum(max(nums[i]-k, 0) for i in xrange(len(nums)//2+1))+
                sum(max(k-nums[i], 0) for i in xrange(len(nums)//2, len(nums))))
