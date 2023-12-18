# Time:  O(n + logr)
# Space: O(logr)

import random


# lc0564
# quick select, math, string
class Solution(object):
    def minimumCost(self, nums):
        """
        :type nums: List[int]
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
    
        def nearest_palindromic(x):
            n = str(x)
            l = len(n)
            result = {10**l+1, 10**(l-1)-1}
            prefix = int(n[:(l+1)/2])
            for i in map(str, (prefix-1, prefix, prefix+1)):
                result.add(int(i+[i, i[:-1]][l%2][::-1]))
            return result

        nth_element(nums, len(nums)//2)
        median = nums[len(nums)//2]
        if len(nums)%2 == 0:
            nth_element(nums, len(nums)//2-1)
            median = (median+nums[len(nums)//2-1])//2
        return min(sum(abs(x-p) for x in nums) for p in nearest_palindromic(median))


# Time:  O(nlogn + logr)
# Space: O(logr)
# lc0564
# sort, math, string
class Solution2(object):
    def minimumCost(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def nearest_palindromic(x):
            n = str(x)
            l = len(n)
            result = {10**l+1, 10**(l-1)-1}
            prefix = int(n[:(l+1)/2])
            for i in map(str, (prefix-1, prefix, prefix+1)):
                result.add(int(i+[i, i[:-1]][l%2][::-1]))
            return result
    
        nums.sort()
        median = nums[len(nums)//2]
        if len(nums)%2 == 0:
            median = (median+nums[len(nums)//2-1])//2
        return min(sum(abs(x-p) for x in nums) for p in nearest_palindromic(median))
