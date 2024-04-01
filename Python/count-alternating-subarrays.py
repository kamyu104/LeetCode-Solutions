# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def countAlternatingSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = curr = 0
        for i in xrange(len(nums)):
            if i-1 >= 0 and nums[i-1] == nums[i]:
                curr = 0
            curr += 1
            result += curr
        return result
