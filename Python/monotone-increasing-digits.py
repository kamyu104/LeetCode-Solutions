# Time:  O(logn) = O(1)
# Space: O(logn) = O(1)

# Given a non-negative integer N,
# find the largest number that is less than or equal to N with monotone increasing digits.
#
# (Recall that an integer has monotone increasing digits if and only
# if each pair of adjacent digits x and y satisfy x <= y.)
#
# Example 1:
# Input: N = 10
# Output: 9
#
# Example 2:
# Input: N = 1234
# Output: 1234
#  
# Example 3:
# Input: N = 332
# Output: 299
#   
# Note: N is an integer in the range [0, 10^9].

class Solution(object):
    def monotoneIncreasingDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        nums = map(int, list(str(N)))
        leftmost_inverted_idx = len(nums)
        for i in reversed(xrange(1, len(nums))):
            if nums[i-1] > nums[i]:
                leftmost_inverted_idx = i
                nums[i-1] -= 1
        for i in xrange(leftmost_inverted_idx, len(nums)):
            nums[i] = 9
        return int("".join(map(str, nums)))
