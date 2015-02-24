# Time:  O(n)
# Space: O(1)
#
# Rotate an array of n elements to the right by k steps.
#
# For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
#
# Note:
# Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
#

class Solution:
    # @param nums, a list of integer
    # @param k, num of steps
    # @return nothing, please modify the nums list in-place.
    def rotate(self, nums, k):
        k %= len(nums)
        self.reverse(nums, 0, len(nums))
        self.reverse(nums, 0, k)
        self.reverse(nums, k, len(nums))
    
    def reverse(self, nums, start, end):
        while start < end:
            nums[start], nums[end-1] = nums[end-1], nums[start]
            start += 1
            end -= 1
  
if __name__ == '__main__':
    nums = [1,2,3,4,5,6,7]
    Solution().rotate(nums, 3)
    print nums
