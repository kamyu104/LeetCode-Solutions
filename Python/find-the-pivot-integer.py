# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def pivotInteger(self, n):
        """
        :type n: int
        :rtype: int
        """
        x = int(((n+1)*n//2)**0.5+0.5)
        return x if x**2 == (n+1)*n//2 else -1
