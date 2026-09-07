# Time:  O(n)
# Space: O(1)

# two pointers
class Solution(object):
    def countGoodRotations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        total, curr = sum(nums), curr = sum(nums[i] for i in xrange(len(nums)//2))
        for i in xrange(len(nums)):
            if curr > total-curr:
                result += 1
            curr += nums[(i+len(nums)//2)%len(nums)]-nums[i]
        return result
