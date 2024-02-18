# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def maxOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 1
        target = nums[0]+nums[1]
        for i in xrange(2, len(nums)-1, 2):
            if nums[i]+nums[i+1] != target:
                break
            result += 1
        return result
