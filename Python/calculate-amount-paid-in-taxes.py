# Time:  O(n)
# Space: O(1)

# simulation
class Solution(object):
    def calculateTax(self, brackets, income):
        """
        :type brackets: List[List[int]]
        :type income: int
        :rtype: float
        """
        result = prev = 0
        for u, p in brackets:
            result += max((min(u, income)-prev)*p/100.0, 0.0)
            prev = u
        return result
