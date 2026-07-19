# Time:  O(1)
# Space: O(1)

# math, parity
class Solution(object):
    def canReach(self, start, target):
        """
        :type start: List[int]
        :type target: List[int]
        :rtype: bool
        """
        return sum(start)%2 == sum(target)%2
