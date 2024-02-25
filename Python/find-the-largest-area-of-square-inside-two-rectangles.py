# Time:  O(n^2)
# Space: O(1)

# brute force, math
class Solution(object):
    def largestSquareArea(self, bottomLeft, topRight):
        """
        :type bottomLeft: List[List[int]]
        :type topRight: List[List[int]]
        :rtype: int
        """
        result = 0
        for i in xrange(len(bottomLeft)):
            for j in xrange(i+1, len(bottomLeft)):
                max_x = max(bottomLeft[i][0], bottomLeft[j][0])
                min_x = min(topRight[i][0], topRight[j][0])
                max_y = max(bottomLeft[i][1], bottomLeft[j][1])
                min_y = min(topRight[i][1], topRight[j][1])
                result = max(result, min(min_x-max_x, min_y-max_y))
        return result**2


# Time:  O(n^2)
# Space: O(1)
# brute force, math
class Solution2(object):
    def largestSquareArea(self, bottomLeft, topRight):
        """
        :type bottomLeft: List[List[int]]
        :type topRight: List[List[int]]
        :rtype: int
        """
        return max(max(min(min(topRight[i][0], topRight[j][0])-max(bottomLeft[i][0], bottomLeft[j][0]), min(topRight[i][1], topRight[j][1])-max(bottomLeft[i][1], bottomLeft[j][1])) for i in xrange(len(bottomLeft)) for j in xrange(i+1, len(bottomLeft))), 0)**2
