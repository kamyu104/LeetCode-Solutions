# Time:  O(n * k)
# Space: O(k)

class Solution(object):
    def minCostII(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        if not costs:
            return 0
        
        n = len(costs)
        k = len(costs[0])
        min_cost = [costs[0], [0] * k]
        for i in xrange(1, n):
            min_1st, min_2nd = float("inf"), float("inf")
            for j in xrange(k):
                if min_1st >= min_cost[(i - 1) % 2][j]:
                    min_1st, min_2nd = min_cost[(i - 1) % 2][j], min_1st
                elif min_2nd >= min_cost[(i - 1) % 2][j]:
                    min_2nd = min_cost[(i - 1) % 2][j]
            for j in xrange(k):
                min_j = min_1st if min_cost[(i - 1) % 2][j] != min_1st else min_2nd
                min_cost[i % 2][j] = costs[i][j] + min_j

        return min(min_cost[(n - 1) % 2])
