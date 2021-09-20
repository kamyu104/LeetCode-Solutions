# Time:  O(nlogn)
# Space: O(n)

class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        nums = sorted(set(nums))
        result = l = 0
        for i in xrange(len(nums)):
            if nums[i] <= nums[i-l]+n-1:
                l += 1
        return n-l


# Time:  O(nlogn)
# Space: O(n)
class Solution2(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        nums = sorted(set(nums))
        result = right = 0
        for left in xrange(len(nums)):
            while right < len(nums) and nums[right] <= nums[left]+n-1:
                right += 1
            result = max(result, right-left)
        return n-result
