# Time:  O(n)
# Space: O(1)

class Solution(object):
    def getMinDistance(self, nums, target, start):
        """
        :type nums: List[int]
        :type target: int
        :type start: int
        :rtype: int
        """
        for i in xrange(len(nums)):
            if (start-i >= 0 and nums[start-i] == target) or \
               (start+i < len(nums) and nums[start+i] == target):
                break
        return i
