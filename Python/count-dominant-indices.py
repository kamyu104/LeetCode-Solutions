# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def dominantIndices(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = total = 0
        for i in xrange(len(nums)):
            if i*nums[~i] > total:
                result += 1
            total += nums[~i]
        return result
