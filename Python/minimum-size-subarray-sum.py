# Time:  O(n)
# Space: O(1)
#
# Given an array of n positive integers and a positive integer s, 
# find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
#
# For example, given the array [2,3,1,2,4,3] and s = 7,
# the subarray [4,3] has the minimal length under the problem constraint.
#
# More practice:
# If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
#

# Sliding window solution.
class Solution:
    # @param {integer} s
    # @param {integer[]} nums
    # @return {integer}
    def minSubArrayLen(self, s, nums):
        start = 0
        sum = 0
        min_len = float("inf")
        for i in xrange(len(nums)):
            sum += nums[i]
            while sum >= s:
                min_len = min(min_len, i - start + 1)
                sum -= nums[start]
                start += 1
        if min_len == float("inf"):
            return 0
        return min_len

# Time:  O(nlogn)
# Space: O(n)
# Binary search solution.
class Solution2:
    # @param {integer} s
    # @param {integer[]} nums
    # @return {integer}
    def minSubArrayLen(self, s, nums):
        min_size = float("inf")
        sum_from_start = [n for n in nums]
        for i in xrange(len(sum_from_start) - 1):
            sum_from_start[i + 1] += sum_from_start[i]
        for i in xrange(len(sum_from_start)):
            end = self.binarySearch(lambda x, y: x <= y, sum_from_start, \
                                    i, len(sum_from_start), \
                                    sum_from_start[i] - nums[i] + s)
            if end < len(sum_from_start):
                min_size = min(min_size,  end  - i + 1)
        if min_size == float("inf"):
            return 0
        return min_size
    
    def binarySearch(self, compare, A, start, end, target):
        while start < end:
            mid = start + (end - start) / 2
            if compare(target, A[mid]):
                end = mid
            else:
                start = mid + 1
        return start
