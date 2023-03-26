# Time:  O(1)
# Space: O(1)

# greedy, math
class Solution(object):
    def kItemsWithMaximumSum(self, numOnes, numZeros, numNegOnes, k):
        """
        :type numOnes: int
        :type numZeros: int
        :type numNegOnes: int
        :type k: int
        :rtype: int
        """
        return min(numOnes, k)-max(k-numOnes-numZeros, 0)
