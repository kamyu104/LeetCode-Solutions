# Time:  O(n)
# Space: O(1)

# one pass solution
class Solution(object):
    def average(self, salary):
        """
        :type salary: List[int]
        :rtype: float
        """
        total, mi, ma = 0, float("inf"), float("-inf")
        for s in salary:
            total += s
            mi, ma = min(mi, s), max(ma, s)
        return 1.0*(total-mi-ma)/(len(salary)-2)


# Time:  O(n)
# Space: O(1)
# one-liner solution
class Solution2(object):
    def average(self, salary):
        """
        :type salary: List[int]
        :rtype: float
        """
        return 1.0*(sum(salary)-min(salary)-max(salary))/(len(salary)-2)
