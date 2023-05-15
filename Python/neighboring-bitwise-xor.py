# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def doesValidArrayExist(self, derived):
        """
        :type derived: List[int]
        :rtype: bool
        """
        return reduce(lambda total, x: total^x, derived, 0) == 0
