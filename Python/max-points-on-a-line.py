# Time:  O(n^2)
# Space: O(n)
#
# Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
#

# Definition for a point
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

class Solution:
    # @param points, a list of Points
    # @return an integer
    def maxPoints(self, points):
        max_points = 0
        for i, start in enumerate(points):
            slope_count, same, current_max = {}, 1, 0
            for j in xrange(i + 1, len(points)):
                end = points[j]
                if start.x == end.x and start.y == end.y:
                    same += 1
                else:
                    slope = float("inf")
                    if start.x - end.x != 0:
                        slope = (start.y - end.y) * 1.0 / (start.x - end.x)
                    if slope not in slope_count:
                        slope_count[slope] = 1
                    else:
                        slope_count[slope] += 1
                        
            for slope in slope_count:
                current_max = max(current_max, slope_count[slope] + same)
                
            max_points = max(max_points, current_max, same)
            
        return max_points

if __name__ == "__main__":
    print Solution().maxPoints([Point(), Point(), Point()])
