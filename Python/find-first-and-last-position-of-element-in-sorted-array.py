# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        def binarySearch(n, check):  # usually use
            left, right = 0, n-1  # search in [0, n-1], return n if not found
            while left <= right:
                mid = left + (right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        def binarySearch2(n, check):  # frequently use
            left, right = 0, n  # search in [0, n), return n if not found
            while left < right:
                mid = left + (right-left)//2
                if check(mid):
                    right = mid
                else:
                    left = mid+1
            return left

        def binarySearch3(n, check):  # never use
            left, right = -1, n-1  # search in (-1, n-1], return n if not found
            while left < right:
                mid = right - (right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid
            return left+1

        def binarySearch4(n, check):  # sometimes use
            left, right = -1, n  # search in (-1, n), return n if not found
            while right-left >= 2:
                mid = left + (right-left)//2
                if check(mid):
                    right = mid
                else:
                    left = mid
            return right  # right = left+1

        # Find the first idx where nums[idx] >= target
        left = binarySearch(len(nums), lambda i: nums[i] >= target)
        if left == len(nums) or nums[left] != target:
            return [-1, -1]
        # Find the first idx where nums[idx] > target
        right = binarySearch(len(nums), lambda i: nums[i] > target)
        return [left, right-1]
