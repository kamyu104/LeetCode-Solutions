# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def minSensors(self, n, m, k):
        """
        :type n: int
        :type m: int
        :type k: int
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b
    
        return ceil_divide(n, 2*k+1)*ceil_divide(m, 2*k+1)
