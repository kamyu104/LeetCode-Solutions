# Time:  O(n)
# Space: O(n)

class Solution(object):
    def findBuildings(self, heights):
        """
        :type heights: List[int]
        :rtype: List[int]
        """
        result = []
        for i, h in enumerate(heights):
            while result and heights[result[-1]] <= h:
                result.pop()
            result.append(i)
        return result


# Time:  O(n)
# Space: O(1)
class Solution2(object):
    def findBuildings(self, heights):
        """
        :type heights: List[int]
        :rtype: List[int]
        """
        result = []
        for i in reversed(xrange(len(heights))):
            if not result or heights[result[-1]] < heights[i]:
                result.append(i)
        result.reverse()
        return result
