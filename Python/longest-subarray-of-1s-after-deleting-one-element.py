# Time:  O(n)
# Space: O(1)

class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count, left = 0, 0
        for right in xrange(len(nums)):
            count += (nums[right] == 0)
            if count >= 2:
                count -= (nums[left] == 0)
                left += 1
        return (right-left+1)-1


# Time:  O(n)
# Space: O(1)
class Solution2(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result, count, left = 0, 0, 0
        for right in xrange(len(nums)):
            count += (nums[right] == 0)
            while count >= 2:
                count -= (nums[left] == 0)
                left += 1
            result = max(result, right-left+1)
        return result-1
