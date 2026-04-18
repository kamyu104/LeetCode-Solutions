# Time:  O(1)
# Space: O(1)

import math


# math, law of cosines
class Solution(object):
    def internalAngles(self, sides):
        """
        :type sides: List[int]
        :rtype: List[float]
        """
        sides.sort()
        a, b, c = sides
        return [acos((b*b+c*c-a*a)/(2.0*b*c))*(180.0/math.pi),
                acos((a*a+c*c-b*b)/(2.0*a*c))*(180.0/math.pi),
                acos((a*a+b*b-c*c)/(2.0*a*b))*(180.0/math.pi)] if a+b > c else []
