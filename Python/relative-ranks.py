# Time:  O(nlogn)
# Space: O(n)

# Given scores of N athletes, find their relative ranks and
# the people with the top three highest scores, who will be
# awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
#
# Example 1:
# Input: [5, 4, 3, 2, 1]
# Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
# Explanation: The first three athletes got the top three highest scores,
# so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
# For the left two athletes, you just need to output
# their relative ranks according to their scores.
# Note:
# N is a positive integer and won't exceed 10,000.
# All the scores of athletes are guaranteed to be unique.

class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        sorted_nums = sorted(nums)[::-1]
        ranks = ["Gold Medal", "Silver Medal", "Bronze Medal"] + map(str, range(4, len(nums) + 1))
        return map(dict(zip(sorted_nums, ranks)).get, nums)
