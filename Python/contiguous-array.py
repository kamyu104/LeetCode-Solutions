# Time:  O(n)
# Space: O(n)

# Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
#
# Example 1:
# Input: [0,1]
# Output: 2
# Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
# Example 2:
# Input: [0,1,0]
# Output: 2
# Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
# Note: The length of the given binary array will not exceed 50,000.

class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result, count = 0, 0
        lookup = {0: 0}

        for i, num in enumerate(nums):
            count += 1 if num == 1 else -1
            if count in lookup:
                result = max(result, i+1 - lookup[count])
            else:
                lookup[count] = i+1
        
        return result
