# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # Find the first idx where nums[idx] >= target
        left = self.binarySearch(lambda x, y: x >= y, nums, target)
        if left >= len(nums) or nums[left] != target:
            return [-1, -1]
        # Find the first idx where nums[idx] > target
        right = self.binarySearch(lambda x, y: x > y, nums, target)
        return [left, right - 1]

    def binarySearch(self, compare, nums, target):
        left, right = 0, len(nums)
        while left < right:
            mid = left + (right - left) / 2
            if compare(nums[mid], target):
                right = mid
            else:
                left = mid + 1
        return left

    def binarySearch2(self, compare, nums, target):
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) / 2
            if compare(nums[mid], target):
                right = mid - 1
            else:
                left = mid + 1
        return left

    def binarySearch3(self, compare, nums, target):
        left, right = -1, len(nums)
        while left + 1 < right:
            mid = left + (right - left) / 2
            if compare(nums[mid], target):
                right = mid
            else:
                left = mid
        return left if left != -1 and compare(nums[left], target) else right


