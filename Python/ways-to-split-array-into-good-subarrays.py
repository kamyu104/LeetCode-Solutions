# Time:  O(n)
# Space: O(1)

# combinatorics
class Solution(object):
    def numberOfGoodSubarraySplits(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        result, prev = 1, -1
        for i in xrange(len(nums)):
            if nums[i] != 1:
                continue
            if prev != -1:
                result = (result*(i-prev))%MOD
            prev = i
        return result if prev != -1 else 0
