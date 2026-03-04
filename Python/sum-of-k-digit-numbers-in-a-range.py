# Time:  O(logr)
# Space: O(1)

# math
class Solution(object):
    def sumOfNumbers(self, l, r, k):
        """
        :type l: int
        :type r: int
        :type k: int
        :rtype: int
        """
        def invmod(x, MOD):
            return pow(x, MOD-2, MOD)
    
        MOD = 10**9+7
        return (((((r+l)*(r-l+1)//2)*pow(r-l+1, k-1, MOD))%MOD)*((((pow(10, k, MOD)-1)%MOD)*invmod(10-1, MOD))%MOD))%MOD
