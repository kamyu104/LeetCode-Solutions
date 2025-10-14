# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = cnt = 2
        for i in xrange(2, len(nums)):
            if nums[i] != nums[i-1]+nums[i-2]:
                cnt = 2
                continue
            cnt += 1
            result = max(result, cnt)
        return result
