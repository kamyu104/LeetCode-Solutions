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
        for x in nums:
            if x^(result&1):
                continue
            result += 1
        return result
