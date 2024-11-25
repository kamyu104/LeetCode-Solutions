# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def canAliceWin(self, n):
        """
        :type n: int
        :rtype: bool
        """
        c = 10
        # (c+(c-l+1))*l/2 <= n
        # l^2-(2*c+1)*l-2*n >= 0
        # l <= ((2*c+1)-((2*c+1)**2-8*n)**0.5)/2
        l = int(((2*c+1)-((2*c+1)**2-8*n)**0.5)/2)
        return l%2 == 1
    
