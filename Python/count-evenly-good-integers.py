# Time:  O(logr)
# Space: O(1)

# math
class Solution(object):
    def countEvenlyGoodIntegers(self, l, r):
        """
        :type l: int
        :type r: int
        :rtype: int
        """
        def count(n):
            if n <= 0:
                return 0
            q, parity = n//10, 0
            while q:
                q, d = divmod(q, 10)
                parity ^= d%2 == 0
            q, r = divmod(n, 10)
            return q*5+r//2+1 if parity else q*5+(r+1)//2

        return count(r)-count(l-1)
