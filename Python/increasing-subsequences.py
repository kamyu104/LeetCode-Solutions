# Time:  O(n * 2^n)
# Space: O(n^2)

# Given an integer array, your task is 
# to find all the different possible increasing 
# subsequences of the given array,
# and the length of an increasing subsequence should be at least 2 .
#
# Example:
# Input: [4, 6, 7, 7]
# Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
# Note:
# The length of the given array will not exceed 15.
# The range of integer in the given array is [-100,100].
# The given array may contain duplicates,
# and two equal integers should also be considered as a special case of increasing sequence.

class Solution(object):
    def findSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def findSubsequencesHelper(nums, pos, seq, result):
            if len(seq) >= 2:
                result.append(list(seq))
            lookup = set()
            for i in xrange(pos, len(nums)):
                if (not seq or nums[i] >= seq[-1]) and \
                   nums[i]  not in lookup:
                    lookup.add(nums[i])
                    seq.append(nums[i])
                    findSubsequencesHelper(nums, i+1, seq, result)
                    seq.pop()

        result, seq = [], []
        findSubsequencesHelper(nums, 0, seq, result)
        return result
