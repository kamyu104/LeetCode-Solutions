# Time:  O(n)
# Space: O(1)

class Solution(object):
    def minCost(self, s, cost):
        """
        :type s: str
        :type cost: List[int]
        :rtype: int
        """
        result = accu = max_cost = 0
        for i in xrange(len(s)):
            if i and s[i] != s[i-1]:
                result += accu-max_cost
                accu = max_cost = 0
            accu += cost[i]
            max_cost = max(max_cost, cost[i])
        result += accu-max_cost
        return result
