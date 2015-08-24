# Time:  O(n)
# Space: O(1)

class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return reduce(operator.xor, nums, \
                      reduce(operator.xor, xrange(len(nums) + 1)))
