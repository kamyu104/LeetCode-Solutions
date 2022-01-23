# Time:  O(nlogn)
# Space: O(1)

# greedy
class Solution(object):
    def minimumCost(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        cost.sort(reverse=True)
        return sum(x for i, x in enumerate(cost) if i%3 != 2)
