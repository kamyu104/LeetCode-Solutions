# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def numberOfCuts(self, n):
        """
        :type n: int
        :rtype: int
        """
        return 0 if n == 1 else n if n%2 else n//2
