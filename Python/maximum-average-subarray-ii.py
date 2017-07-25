# Time:  O(n)
# Space: O(n)


# Given an array consisting of n integers, find the contiguous subarray whose length is greater than or equal to k that has the maximum average value. And you need to output the maximum average value.
#
# Example 1:
# Input: [1,12,-5,-6,50,3], k = 4
# Output: 12.75
# Explanation:
# when length is 5, maximum average value is 10.8,
# when length is 6, maximum average value is 9.16667.
# Thus return 12.75.
# Note:
# 1 <= k <= n <= 10,000.
# Elements of the given array will be in range [-10,000, 10,000].
# The answer with the calculation error less than 10-5 will be accepted.

class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        def getDelta(avg, accu):
            minval, minval_pos = 2**32, -1
            delta = 0
            for i in xrange(len(nums)):
                accu[i+1] = nums[i] + accu[i] - avg
                if i >= (k-1):
                    if accu[i-k+1] < minval:
                        minval = accu[i-k+1]
                        minval_pos = i-k+1
                    if accu[i+1] - minval >= 0:
                        delta = max(delta, 1.0 * (accu[i+1] - minval) / (i+1 - minval_pos))
            return delta

        accu = [0.0] * (len(nums) + 1)
        left, delta = min(nums), float("inf")
        while delta > 1e-5:
            delta = getDelta(left, accu)
            left += delta
        return left
