# Time:  O(1)
# Space: O(1)

# math, bit manipulation
class Solution(object):
    def smallestEvenMultiple(self, n):
        """
        :type n: int
        :rtype: int
        """
        return n<<(n&1)
