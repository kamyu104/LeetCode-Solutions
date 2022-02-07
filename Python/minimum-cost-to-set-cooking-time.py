# Time:  O(1)
# Space: O(1)

# simulation
class Solution(object):
    def minCostSetTime(self, startAt, moveCost, pushCost, targetSeconds):
        """
        :type startAt: int
        :type moveCost: int
        :type pushCost: int
        :type targetSeconds: int
        :rtype: int
        """     
        def cost(m, s):
            if not (0 <= m <= 99 and s <= 99):
                return float("inf")
            result = 0
            curr = startAt
            for x in map(int, list(str(m*100 + s))):
                result += (moveCost if x != curr else 0)+pushCost
                curr = x
            return result

        m, s = divmod(targetSeconds, 60)
        return min(cost(m, s), cost(m-1, s+60))
