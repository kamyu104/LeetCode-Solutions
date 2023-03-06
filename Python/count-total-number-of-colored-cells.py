# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def coloredCells(self, n):
        """
        :type n: int
        :rtype: int
        """
        return n**2+(n-1)**2


# Time:  O(1)
# Space: O(1)
# math
class Solution2(object):
    def coloredCells(self, n):
        """
        :type n: int
        :rtype: int
        """
        return (1+(1+2*(n-1)))*n//2*2-(2*n-1)
