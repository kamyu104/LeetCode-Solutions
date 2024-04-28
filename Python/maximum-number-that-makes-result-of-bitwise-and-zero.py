# Time:  O(1)
# Space: O(1)

# bit manipulation
class Solution(object):
    def maxNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        return (1<<(n.bit_length()-1))-1
