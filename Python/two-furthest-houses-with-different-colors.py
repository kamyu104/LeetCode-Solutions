# Time:  O(n)
# Space: O(1)

class Solution(object):
    def maxDistance(self, colors):
        """
        :type colors: List[int]
        :rtype: int
        """
        result = 0
        for i, x in enumerate(colors):
            if x != colors[0]:
                result = max(result, i)
            if x != colors[-1]:
                result = max(result, len(colors)-1-i)
        return result

