# Time:  O(n)
# Space: O(1)

# prefix sum
class Solution(object):
    def smallestBalancedIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = sum(nums), 1
        for i in reversed(xrange(len(nums))):
            left -= nums[i]
            if left < right:
                break
            if left == right:
                return i
            right *= nums[i]
        return -1
