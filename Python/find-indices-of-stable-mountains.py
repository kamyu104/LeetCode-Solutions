# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def stableMountains(self, height, threshold):
        """
        :type height: List[int]
        :type threshold: int
        :rtype: List[int]
        """
        return [i for i in xrange(1, len(height)) if height[i-1] > threshold]
