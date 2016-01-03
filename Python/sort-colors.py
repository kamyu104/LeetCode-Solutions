# Time:  O(n)
# Space: O(1)
#
# Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, 
# with the colors in the order red, white and blue.
# 
# Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
# 
# Note:
# You are not suppose to use the library's sort function for this problem.
# 
# click to show follow up.
# 
# Follow up:
# A rather straight forward solution is a two-pass algorithm using counting sort.
# First, iterate the array counting number of 0's, 1's, and 2's, 
# then overwrite array with total number of 0's, then 1's and followed by 2's.
# 
# Could you come up with an one-pass algorithm using only constant space?
#

class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        def triPartition(nums, target):
            i, j, n = 0, 0, len(nums) - 1
            
            while j <= n:
                if nums[j] < target:
                    nums[i], nums[j] = nums[j], nums[i]
                    i += 1
                    j += 1
                elif nums[j] > target:
                    nums[j], nums[n] = nums[n], nums[j]
                    n -= 1
                else:
                    j += 1

        triPartition(nums, 1)

if __name__ == "__main__":
    A = [2, 1, 1, 0, 0, 2]
    Solution().sortColors(A)
    print A
