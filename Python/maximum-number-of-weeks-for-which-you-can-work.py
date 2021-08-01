# Time:  O(n)
# Space: O(1)

class Solution(object):
    def numberOfWeeks(self, milestones):
        """
        :type milestones: List[int]
        :rtype: int
        """
        total, max_num = sum(milestones), max(milestones)
        other_total = (total-max_num)
        return other_total+min(other_total+1, max_num)
