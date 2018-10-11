# Time:  O(n)
# Space: O(1)

class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result, local_max = 0, 0
        for n in nums:
            local_max = (local_max + 1 if n else 0)
            result = max(result, local_max)
        return result

