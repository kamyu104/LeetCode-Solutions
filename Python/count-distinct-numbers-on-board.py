# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def distinctIntegers(self, n):
        """
        :type n: int
        :rtype: int
        """
        return n-1 if n >= 2 else 1
