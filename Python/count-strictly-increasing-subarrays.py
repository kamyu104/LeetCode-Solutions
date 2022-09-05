# Time:  O(n)
# Space: O(1)

# two pointers
class Solution(object):
    def countSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = l = 1
        for i in xrange(1, len(nums)):
            if nums[i-1] >= nums[i]:
                l = 0
            l += 1
            result += l
        return result


# Time:  O(n)
# Space: O(1)
# two pointers
class Solution2(object):
    def countSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = left = 0
        for right in xrange(len(nums)):
            if not (right-1 >= 0 and nums[right-1] < nums[right]):
                left = right
            result += right-left+1
        return result
