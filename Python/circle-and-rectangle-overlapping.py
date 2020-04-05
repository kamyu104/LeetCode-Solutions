# Time:  O(1)
# Space: O(1)

class Solution(object):
    def checkOverlap(self, radius, x_center, y_center, x1, y1, x2, y2):
        """
        :type radius: int
        :type x_center: int
        :type y_center: int
        :type x1: int
        :type y1: int
        :type x2: int
        :type y2: int
        :rtype: bool
        """
        x1 -= x_center
        y1 -= y_center
        x2 -= x_center
        y2 -= y_center
        x = x1 if x1 > 0 else x2 if x2 < 0 else 0
        y = y1 if y1 > 0 else y2 if y2 < 0 else 0
        return x**2 + y**2 <= radius**2


# Time:  O(1)
# Space: O(1)
class Solution2(object):
    def checkOverlap(self, radius, x_center, y_center, x1, y1, x2, y2):
        """
        :type radius: int
        :type x_center: int
        :type y_center: int
        :type x1: int
        :type y1: int
        :type x2: int
        :type y2: int
        :rtype: bool
        """
        x1 -= x_center
        y1 -= y_center
        x2 -= x_center
        y2 -= y_center        
        x = min(abs(x1), abs(x2)) if x1*x2 > 0 else 0
        y = min(abs(y1), abs(y2)) if y1*y2 > 0 else 0
        return x**2 + y**2 <= radius**2
