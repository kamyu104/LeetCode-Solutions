# Time:  O(1)
# Space: O(1)

class Solution(object):
    def isSameAfterReversals(self, num):
        """
        :type num: int
        :rtype: bool
        """
        return num == 0 or num%10
