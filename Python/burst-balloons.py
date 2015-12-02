# Time:  O(n^3)
# Space: O(n^2)

# Given n balloons, indexed from 0 to n-1. 
# Each balloon is painted with a number on it 
# represented by array nums. 
# You are asked to burst all the balloons.
# If the you burst balloon i you will get 
# nums[left] * nums[i] * nums[right] coins. 
# Here left and right are adjacent indices of i. 
# After the burst, the left and right then
# becomes adjacent.
#
# Find the maximum coins you can collect by 
# bursting the balloons wisely.
#
# Note: 
# (1) You may imagine nums[-1] = nums[n] = 1.
#     They are not real therefore you can not burst them.
# (2) 0 <= n <= 500, 0 <= nums[i] <= 100
#
# Example:
#
# Given [3, 1, 5, 8]
#
# Return 167
#
#     nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
#   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
#

class Solution(object):
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        coins = [1] + [i for i in nums if i > 0] + [1]
        n = len(coins)
        max_coins = [[0 for _ in xrange(n)] for _ in xrange(n)]
    
        for k in xrange(2, n):
            for left in xrange(n - k):
                right = left + k
                for i in xrange(left + 1, right):
                    max_coins[left][right] = max(max_coins[left][right], \
                           coins[left] * coins[i] * coins[right] + \
                           max_coins[left][i] + max_coins[i][right])

        return max_coins[0][-1]
  
