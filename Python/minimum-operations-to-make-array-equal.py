# Time:  O(1)
# Space: O(1)

class Solution(object):
    def minOperations(self, n):
        """
        :type n: int
        :rtype: int
        """
        # total = sum(2i+1 for i in xrange(n)) = n^2
        # left_half_total = sum(2i+1 for i in xrange(n//2)) = (n//2)^2
        # result = (n//2) * (total//n) - left_half_total = (n//2)*(n-n//2) = (n//2)*((n+1)//2)
        return (n//2)*((n+1)//2)
