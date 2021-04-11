# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        start, step, direction = 1, 2, 1
        while n > 1:
            start += direction * (step * (n//2) - step//2)
            n //= 2
            step *= 2
            direction *= -1
        return start
