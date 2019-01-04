# Time:  O(n)
# Space: O(1)

class Solution(object):
    # @param num, a list of integer
    # @return an integer
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        last, now = 0, 0
        for i in nums:
            last, now = now, max(last + i, now)
        return now


