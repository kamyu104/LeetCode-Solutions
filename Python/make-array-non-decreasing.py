# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def maximumPossibleSize(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = prev = 0
        for x in nums:
            if prev <= x:
                prev = x
                result += 1
        return result
