# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def passThePillow(self, n, time):
        """
        :type n: int
        :type time: int
        :rtype: int
        """
        return n-abs((n-1)-(time%(2*(n-1))))
