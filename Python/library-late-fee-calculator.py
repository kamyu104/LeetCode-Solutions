# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def lateFee(self, daysLate):
        """
        :type daysLate: List[int]
        :rtype: int
        """
        return sum(1 if i == 1 else 3*i if i >= 6 else 2*i for i in daysLate)
