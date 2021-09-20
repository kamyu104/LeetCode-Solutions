# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def unique(nums):
            left = 0
            for right in xrange(1, len(nums)):
                if nums[left] != nums[right]:
                    left += 1
                    nums[left] = nums[right]
            return left

        def erase(nums, i):
            while len(nums) > i+1:
                nums.pop()

        n = len(nums)
        nums.sort()
        erase(nums, unique(nums))
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
