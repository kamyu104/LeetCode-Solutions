# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def numberOfEmployeesWhoMetTarget(self, hours, target):
        """
        :type hours: List[int]
        :type target: int
        :rtype: int
        """
        return sum(x >= target for x in hours)
