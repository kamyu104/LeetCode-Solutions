# Time:  O(n)
# Space: O(1)
#
# Note: This is an extension of House Robber.
#
# After robbing those houses on that street, the thief has found himself a new place 
# for his thievery so that he will not get too much attention. This time, all houses 
# at this place are arranged in a circle. That means the first house is the neighbor 
# of the last one. Meanwhile, the security system for these houses remain the same as 
# for those in the previous street.
#
# Given a list of non-negative integers representing the amount of money of each house, 
# determine the maximum amount of money you can rob tonight without alerting the police.
#
class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def rob(self, nums):
        if len(nums) == 0:
            return 0
            
        if len(nums) == 1:
            return nums[0]
        
        return max(self.robRange(nums, 0, len(nums) - 1),\
                   self.robRange(nums, 1, len(nums)))
    
    def robRange(self, nums, start, end):
        num_i, num_i_1 = nums[start], 0
        for i in xrange(start + 1, end):
            num_i_1, num_i_2 = num_i, num_i_1
            num_i = max(nums[i] + num_i_2, num_i_1);
        
        return num_i

if __name__ == '__main__':
        print Solution().rob([8,4,8,5,9,6,5,4,4,10])
