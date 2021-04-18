# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def maxIceCream(self, costs, coins):
        """
        :type costs: List[int]
        :type coins: int
        :rtype: int
        """
        costs.sort()
        for i, c in enumerate(costs):
            coins -= c
            if coins < 0:
                return i
        return len(costs)
