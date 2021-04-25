# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def sumBase(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        result = 0
        while n:
            n, r = divmod(n, k)
            result += r
        return result
