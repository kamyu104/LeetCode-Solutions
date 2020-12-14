# Time:  O(nlogn)
# Space: O(n)

class Solution(object):
    def stoneGameVI(self, aliceValues, bobValues):
        """
        :type aliceValues: List[int]
        :type bobValues: List[int]
        :rtype: int
        """
        sorted_vals = sorted(((a, b) for a, b in zip(aliceValues, bobValues)), key=sum, reverse=True)
        return cmp(sum(a for a, _ in sorted_vals[::2]), sum(b for _, b in sorted_vals[1::2]))
