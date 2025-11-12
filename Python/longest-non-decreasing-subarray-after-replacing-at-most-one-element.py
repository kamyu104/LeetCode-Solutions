# Time:  O(n)
# Space: O(n)

# prefix sum
class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        right = [1]*len(nums)
        for i in reversed(xrange(len(nums)-1)):
            if nums[i] <= nums[i+1]:
                right[i] = right[i+1]+1
        result = min(max(right)+1, len(nums))
        left = 1
        for i in xrange(1, len(nums)-1):
            if nums[i-1] <= nums[i+1]:
                result = max(result, left+1+right[i+1])
            if nums[i-1] <= nums[i]:
                left += 1
            else:
                left = 1
        return result


# Time:  O(n)
# Space: O(n)
# prefix sum
class Solution2(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = [1]*len(nums)
        for i in xrange(len(nums)-1):
            if nums[i] <= nums[i+1]:
                left[i+1] = left[i]+1
        right = [1]*len(nums)
        for i in reversed(xrange(len(nums)-1)):
            if nums[i] <= nums[i+1]:
                right[i] = right[i+1]+1
        result = min(max(left)+1, len(nums))
        for i in xrange(1, len(nums)-1):
            if nums[i-1] <= nums[i+1]:
                result = max(result, left[i-1]+1+right[i+1])
        return result
