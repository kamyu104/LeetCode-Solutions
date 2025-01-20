# Time:  O(n)
# Space: O(n)

# difference array
class Solution(object):
    def subarraySum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        diff = [0]*(len(nums)+1)
        for i, x in enumerate(nums):
            diff[max(i-x, 0)] += 1
            diff[i+1] -= 1
        for i in xrange(len(nums)):
            diff[i+1] += diff[i]
        return sum(nums[i]*diff[i] for i in xrange(len(nums)))
