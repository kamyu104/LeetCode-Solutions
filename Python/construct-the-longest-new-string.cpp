# Time:  O(1)
# Space: O(1)

# constructive algorithms, math
class Solution(object):
    def longestString(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: int
        """
        return ((min(x, y)*2+int(x != y))+z)*2
