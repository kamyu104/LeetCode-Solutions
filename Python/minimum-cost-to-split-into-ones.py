# Time:  O(1)
# Space: O(1)

# combinatorics
class Solution(object):
    def minCost(self, n):
        """
        :type n: int
        :rtype: int
        """
        def nC2(n):
            return n*(n-1)//2

        return nC2(n)
