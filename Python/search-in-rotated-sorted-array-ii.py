# Time:  O(logn)
# Space: O(1)
#
# Follow up for "Search in Rotated Sorted Array":
# What if duplicates are allowed?
# 
# Would this affect the run-time complexity? How and why?
# 
# Write a function to determine if a given target is in the array.
#

class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left, right = 0, len(nums) - 1
        
        while left <= right:
            mid = left + (right - left) / 2
            
            if nums[mid] == target:
                return True
            if nums[mid] == nums[left]:
                left += 1
            elif (nums[mid] > nums[left] and nums[left] <= target < nums[mid]) or \
                 (nums[mid] < nums[left] and not (nums[mid] < target <= nums[right])):
                right = mid - 1
            else:
                left = mid + 1

        return False
        

if __name__ == "__main__":
    print Solution().search([3, 5, 1], 3)
    print Solution().search([2, 2, 3, 3, 4, 1], 1)
    print Solution().search([4, 4, 5, 6, 7, 0, 1, 2], 5)
