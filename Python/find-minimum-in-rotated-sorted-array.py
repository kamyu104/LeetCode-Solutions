from __future__ import print_function
# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 0, len(nums)
        target = nums[-1]

        while left < right:
            mid = left + (right - left) / 2

            if nums[mid] <= target:
                right = mid
            else:
                left = mid + 1

        return nums[left]

class Solution2(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 0, len(nums) - 1
        while left < right and nums[left] >= nums[right]:
            mid = left + (right - left) / 2

            if nums[mid] < nums[left]:
                right = mid
            else:
                left = mid + 1

        return nums[left]

if __name__ == "__main__":
    print(Solution().findMin([1]))
    print(Solution().findMin([1, 2]))
    print(Solution().findMin([2, 1]))
    print(Solution().findMin([3, 1, 2]))
    print(Solution().findMin([2, 3, 1]))

