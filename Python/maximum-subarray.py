# Time:  O(n)
# Space: O(1)
#
# Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
# 
# For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
# the contiguous subarray [4,-1,2,1] has the largest sum = 6.
# 
# click to show more practice.
# 
# More practice:
# If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
#

class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxSubArray(self, A):
        global_max, local_max = float("-inf"), 0
        for x in A:
            local_max = max(0, local_max + x)
            global_max = max(global_max, local_max)
        return global_max

if __name__ == "__main__":
    print Solution().maxSubArray([-2,1,-3,4,-1,2,1,-5,4])