# Time:  O(logn)
# Space: O(1)

# bit manipulation
class Solution(object):
    def minBitFlips(self, start, goal):
        """
        :type start: int
        :type goal: int
        :rtype: int
        """
        return bin(start^goal).count('1')
