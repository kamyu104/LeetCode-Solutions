# Time:  O(n * k)
# Space: O(k)

class Solution2(object):
    def minCostII(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        return min(reduce(self.combine, costs)) if costs else 0

    def combine(self, tmp, house):
        smallest, k, i = min(tmp), len(tmp), tmp.index(min(tmp))
        tmp, tmp[i] = [smallest] * k, min(tmp[:i] + tmp[i+1:])
        return map(sum, zip(tmp, house))


class Solution2(object):
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
            smallest, second_smallest = float("inf"), float("inf")
            for j in xrange(k):
                if min_cost[(i - 1) % 2][j] < smallest:
                    smallest, second_smallest = min_cost[(i - 1) % 2][j], smallest
                elif min_cost[(i - 1) % 2][j] < second_smallest:
                    second_smallest = min_cost[(i - 1) % 2][j]
            for j in xrange(k):
                min_j = smallest if min_cost[(i - 1) % 2][j] != smallest else second_smallest
                min_cost[i % 2][j] = costs[i][j] + min_j

        return min(min_cost[(n - 1) % 2])

