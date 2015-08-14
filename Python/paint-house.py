# Time:  O(n)
# Space: O(1)

class Solution:
    # @param {integer[][]} costs
    # @return {integer}
    def minCost(self, costs):
        if not costs:
            return 0
        
        min_cost = [costs[0], [0, 0, 0]]
        
        n = len(costs)
        for i in xrange(1, n):
            min_cost[i % 2][0] = costs[i][0] + \
                                 min(min_cost[(i - 1) % 2][1], min_cost[(i - 1) % 2][2])
            min_cost[i % 2][1] = costs[i][1] + \
                                 min(min_cost[(i - 1) % 2][0], min_cost[(i - 1) % 2][2])
            min_cost[i % 2][2] = costs[i][2] + \
                                 min(min_cost[(i - 1) % 2][0], min_cost[(i - 1) % 2][1])

        return min(min_cost[(n - 1) % 2][0], min_cost[(n - 1) % 2][1], min_cost[(n - 1) % 2][2])

# Time:  O(n)
# Space: O(n)
class Solution2:
    # @param {integer[][]} costs
    # @return {integer}
    def minCost(self, costs):
        if not costs:
            return 0
        
        min_cost = [costs[0], [0, 0, 0]]
        
        n = len(costs)
        for i in xrange(1, n):
            costs[i][0] += min(costs[i - 1][1], costs[i - 1][2])
            costs[i][1] += min(costs[i - 1][0], costs[i - 1][2])
            costs[i][2] += min(costs[i - 1][0], costs[i - 1][1])
        
        return min(costs[n - 1][0], costs[n - 1][1], costs[n - 1][2])
