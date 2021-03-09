# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def checkPowersOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        while n > 0:
            if n%3 == 2:
                return False
            n //= 3
        return True
