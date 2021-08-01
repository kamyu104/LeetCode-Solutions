# Time:  O(n)
# Space: O(1)

class Solution(object):
    def numberOfWeeks(self, milestones):
        """
        :type milestones: List[int]
        :rtype: int
        """
        total, max_num = sum(milestones), max(milestones)
        return min((total-max_num)+((total-max_num)+1), total)
