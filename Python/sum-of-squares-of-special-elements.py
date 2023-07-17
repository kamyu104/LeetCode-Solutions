# Time:  O(sqrt(n))
# Space: O(1)

# number theory
class Solution(object):
    def sumOfSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for i in xrange(1, int(len(nums)**0.5)+1):
            if len(nums)%i:
                continue
            result += nums[i-1]**2
            if len(nums)//i != i:
                result += nums[len(nums)//i-1]**2
        return result
