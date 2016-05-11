# Time:  O(logn) ~ O(n)
# Space: O(1)
#
# Follow up for "Find Minimum in Rotated Sorted Array":
# What if duplicates are allowed?
# 
# Would this affect the run-time complexity? How and why?
# Suppose a sorted array is rotated at some pivot unknown to you beforehand.
# 
# (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
# 
# Find the minimum element.
# 
# The array may contain duplicates.
#

class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 0, len(nums) - 1
        while left < right:
            mid = left + (right - left) / 2

            if nums[mid] == nums[right]:
                right -= 1
            elif nums[mid] < nums[right]:
                right = mid
            else:
                left = mid + 1

        return nums[left]


class Solution2(object):
    def findMin(self, nums):
        left, right = 0, len(nums) - 1
           
        while left < right and nums[left] >= nums[right]:
            mid = left + (right - left) / 2
            
            if nums[mid] > nums[left]:
                left = mid + 1
            elif nums[mid] < nums[left]:
                right = mid
            else:
                left += 1

        return nums[left]


if __name__ == "__main__":
    print Solution().findMin([3, 1, 1, 2, 2, 3])
    print Solution2().findMin([2, 2, 2, 3, 3, 1])
