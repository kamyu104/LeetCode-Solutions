# Time: O(n)
# Space: O(n)
#
# Given an array of integers, find two numbers such that they add up to a specific target number.
# The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
# You may assume that each input would have exactly one solution.
#
# Input: numbers={2, 7, 11, 15}, target=9
# Output: index1=1, index2=2
#

class Solution:
    def twoSum(self, nums, target):
        lookup = {}
        for i, num in enumerate(nums):
            if target - num in lookup:
                return (lookup[target - num] + 1, i + 1)
            lookup[num] = i

if __name__ == '__main__':
	print "index1=%d, index2=%d" % Solution().twoSum((2, 7, 11, 15), 9)