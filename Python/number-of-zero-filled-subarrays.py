# Time:  O(n)
# Space: O(1)

# two pointers, combinatorics
class Solution(object):
    def zeroFilledSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        prev = -1
        for i in xrange(len(nums)):
            if nums[i]:
                prev = i
                continue
            result += i-prev
        return result
