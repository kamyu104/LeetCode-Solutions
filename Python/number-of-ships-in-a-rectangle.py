# Time:  O(s * log(m * n)), s is the max number of ships, which is 10 in this problem
# Space: O(log(m * n))

# """
# This is Sea's API interface.
# You should not implement it, or speculate about its implementation
# """
class Sea(object):
   def hasShips(self, topRight, bottomLeft):
       """
       :type topRight: Point
		 :type bottomLeft: Point
       :rtype bool
       """
       pass

class Point(object):
	def __init__(self, x, y):
		self.x = x
		self.y = y

class Solution(object):
    def countShips(self, sea, topRight, bottomLeft):
        """
        :type sea: Sea
        :type topRight: Point
        :type bottomLeft: Point
        :rtype: integer
        """
        result = 0
        if topRight.x >= bottomLeft.x and \
           topRight.y >= bottomLeft.y and \
           sea.hasShips(topRight, bottomLeft):
            if (topRight.x, topRight.y) == (bottomLeft.x, bottomLeft.y):
                return 1
            mid_x, mid_y = (topRight.x+bottomLeft.x)//2, (topRight.y+bottomLeft.y)//2
            result += self.countShips(sea, topRight, Point(mid_x+1, mid_y+1))
            result += self.countShips(sea, Point(mid_x, topRight.y), Point(bottomLeft.x, mid_y+1))
            result += self.countShips(sea, Point(topRight.x, mid_y), Point(mid_x+1, bottomLeft.y))
            result += self.countShips(sea, Point(mid_x, mid_y), bottomLeft)
        return result
