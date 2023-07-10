# Time:  O(1)
# Space: O(1)

# greedy
class Solution(object):
    def theMaximumAchievableX(self, num, t):
        """
        :type num: int
        :type t: int
        :rtype: int
        """
        return num+2*t
