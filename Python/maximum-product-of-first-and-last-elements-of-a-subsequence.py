# Time:  O(n)
# Space: O(1)

# two pointers, sliding window
class Solution(object):
    def maximumProduct(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        result = mx = float("-inf")
        mn = float("inf")
        for i in xrange(len(nums)-(m-1)):
            mx = max(mx, nums[i])
            mn = min(mn, nums[i])
            result = max(result, nums[i+(m-1)]*mx, nums[i+(m-1)]*mn)
        return result
