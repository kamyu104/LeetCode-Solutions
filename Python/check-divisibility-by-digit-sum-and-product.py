# Time:  O(logn)
# Space: O(1)

# math
class Solution(object):
    def checkDivisibility(self, n):
        """
        :type n: int
        :rtype: bool
        """
        curr = n
        total, product = 0, 1
        while curr:
            curr, r = divmod(curr, 10)
            total += r
            product *= r
        return n%(total+product) == 0
