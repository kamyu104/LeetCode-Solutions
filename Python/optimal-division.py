# Time:  O(n)
# Space: O(1)

# Given a list of positive integers, the adjacent integers will perform the float division.
# For example, [2,3,4] -> 2 / 3 / 4.
#
# However, you can add any number of parenthesis at any position to change the priority of operations.
# You should find out how to add parenthesis to get the maximum result,
# and return the corresponding expression in string format. Your expression should NOT contain redundant parenthesis.
#
# Example:
# Input: [1000,100,10,2]
# Output: "1000/(100/10/2)"
# Explanation:
# 1000/(100/10/2) = 1000/((100/10)/2) = 200
# However, the bold parenthesis in "1000/((100/10)/2)" are redundant, 
# since they don't influence the operation priority. So you should return "1000/(100/10/2)". 
#
# Other cases:
# 1000/(100/10)/2 = 50
# 1000/(100/(10/2)) = 50
# 1000/100/10/2 = 0.5
# 1000/100/(10/2) = 2
# Note:
#
# The length of the input array is [1, 10].
# Elements in the given array will be in range [2, 1000].
# There is only one optimal division for each test case.

class Solution(object):
    def optimalDivision(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        if len(nums) == 1:
            return str(nums[0])
        if len(nums) == 2:
            return str(nums[0]) + "/" + str(nums[1])
        result = [str(nums[0]) + "/(" + str(nums[1])]
        for i in xrange(2, len(nums)):
            result += "/" + str(nums[i])
        result += ")"
        return "".join(result)
