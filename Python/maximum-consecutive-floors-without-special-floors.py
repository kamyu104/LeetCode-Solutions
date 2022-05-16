# Time:  O(nlogn)
# Space: O(1)

# sort
class Solution(object):
    def maxConsecutive(self, bottom, top, special):
        """
        :type bottom: int
        :type top: int
        :type special: List[int]
        :rtype: int
        """
        special.sort()
        result = max(special[0]-bottom, top-special[-1])
        for i in xrange(1, len(special)):
            result = max(result, special[i]-special[i-1]-1)
        return result
