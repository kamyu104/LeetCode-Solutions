from __future__ import print_function
# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 0, len(nums) - 1

        while left < right:
            mid = left + (right - left) / 2
            if nums[mid] > nums[mid + 1]:
                right = mid
            else:
                left = mid + 1

        return left

if __name__ == "__main__":
   # print Solution().findPeakElement([1,2,1])
    print(Solution().findPeakElement([1,2,3,1]))

