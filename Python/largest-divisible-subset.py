# Time:  O(n^2)
# Space: O(n)

# Given a set of distinct positive integers,
# find the largest subset such that every pair (Si, Sj) of
# elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
#
# If there are multiple solutions, return any subset is fine.
#
# Example 1:
#
# nums: [1,2,3]
#
# Result: [1,2] (of course, [1,3] will also be ok)
# Example 2:
#
# nums: [1,2,4,8]
#
# Result: [1,2,4,8]

class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if not nums:
            return []

        nums.sort()
        dp = [1] * (len(nums) + 1)
        prev = [-1] * len(nums)
        largest_idx = 1
        for i in xrange(1, len(nums)+1):
            for j in xrange(1, i):
                if nums[i-1] % nums[j-1] == 0:
                    if dp[i] < dp[j] + 1:
                        dp[i] = dp[j] + 1
                        prev[i-1] = j-1
                        if dp[largest_idx] < dp[i]:
                            largest_idx = i
        result = []
        i = largest_idx - 1
        while i != -1:
            result.append(nums[i])
            i = prev[i]
        return result[::-1]
