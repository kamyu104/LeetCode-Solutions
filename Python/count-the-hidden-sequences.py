# Time:  O(n)
# Space: O(1)

# math
class Solution(object):
    def numberOfArrays(self, differences, lower, upper):
        """
        :type differences: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        total = mn = mx = 0
        for x in differences:
            total += x
            mn = min(mn, total)
            mx = max(mx, total)
        return max((upper-lower)-(mx-mn)+1, 0)
