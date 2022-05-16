# Time:  O(n)
# Space: O(1)

# prefix sum
class Solution(object):
    def waysToSplitArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        total = sum(nums)
        result = curr = 0
        for i in xrange(len(nums)-1):
            curr += nums[i]
            result += int(curr >= total-curr)
        return result
