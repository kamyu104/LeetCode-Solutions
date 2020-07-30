# Time:  O(n)
# Space: O(1)

class Solution(object):
    def countOdds(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: int
        """
        return (high+1)//2 - ((low-1)+1)//2
