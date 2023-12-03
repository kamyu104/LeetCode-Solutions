# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def findPeaks(self, mountain):
        """
        :type mountain: List[int]
        :rtype: List[int]
        """
        return [i for i in xrange(1, len(mountain)-1) if mountain[i-1] < mountain[i] > mountain[i+1]]
