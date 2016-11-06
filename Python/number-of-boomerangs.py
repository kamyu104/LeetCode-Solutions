# Time:  O(n^2)
# Space: O(n)

# Given n points in the plane that are all pairwise distinct, 
# a "boomerang" is a tuple of points (i, j, k) such that the distance
# between i and j equals the distance between i and k (the order of the tuple matters).
#
# Find the number of boomerangs. You may assume that n will be at most 500
# and coordinates of points are all in the range [-10000, 10000] (inclusive).
#
# Example:
# Input:
# [[0,0],[1,0],[2,0]]
#
# Output:
# 2
#
# Explanation:
# The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]

class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        result = 0

        for i in xrange(len(points)):
            group = collections.defaultdict(int)
            for j in xrange(len(points)):
                if j == i:
                    continue
                dx, dy =  points[i][0] - points[j][0], points[i][1] - points[j][1]
                group[dx**2 + dy**2] += 1
            
            for _, v in group.iteritems():
                if v > 1:
                    result += v * (v-1)
        
        return result
