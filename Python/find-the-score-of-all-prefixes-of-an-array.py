# Time:  O(n)
# Space: O(1)

# prefix sum
class Solution(object):
    def findPrefixScore(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        curr = 0
        for i in xrange(len(nums)):
            curr = max(curr, nums[i])
            nums[i] += (nums[i-1] if i-1 >= 0 else 0)+curr
        return nums
