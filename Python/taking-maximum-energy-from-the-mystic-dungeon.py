# Time:  O(n)
# Space: O(k)

# greedy, kadane's algorithm
class Solution(object):
    def maximumEnergy(self, energy, k):
        """
        :type energy: List[int]
        :type k: int
        :rtype: int
        """
        result = [float("-inf")]*k
        for i, x in enumerate(energy):
            result[i%k] = max(result[i%k], 0)+x
        return max(result)
