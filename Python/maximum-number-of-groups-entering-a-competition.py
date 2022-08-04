# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def maximumGroups(self, grades):
        """
        :type grades: List[int]
        :rtype: int
        """
        # (1+x)*x/2 <= len(grades)
        # => x <= ((1+8*len(grades))**0.5-1)/2.0
        return int(((1+8*len(grades))**0.5-1)/2.0)
