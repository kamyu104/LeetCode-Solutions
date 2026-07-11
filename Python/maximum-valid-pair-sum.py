# Time:  O(n)
# Space: O(1)

# prefix sum
class Solution(object):
    def maxValidPairSum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result = prefix = 0
        for i in xrange(len(nums)-k):
            prefix = max(prefix, nums[i])
            result = max(result, prefix+nums[i+k])
        return result
