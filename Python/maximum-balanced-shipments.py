# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def maxBalancedShipments(self, weight):
        """
        :type weight: List[int]
        :rtype: int
        """
        result = mx = 0
        for x in weight:
            if x < mx:
                mx = 0
                result += 1
            else:
                mx = x
        return result
