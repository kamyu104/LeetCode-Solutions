# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for i in xrange(len(nums)-2):
            if nums[i]:
                continue
            nums[i+1] ^= 1
            nums[i+2] ^= 1
            result += 1
        return result if nums[-2] == nums[-1] == 1 else -1
