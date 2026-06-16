# Time:  O(m * n)
# Space: O(1)

# greedy
class Solution(object):
    def maxRatings(self, units):
        """
        :type units: List[List[int]]
        :rtype: int
        """
        def top2(a):  # Time: O(k * n)
            mn1 = mn2 = float("inf")
            for x in a:
                if x < mn1:
                    mn1, mn2 = x, mn1
                elif x < mn2:
                    mn2 = x
            return mn1, mn2
    
        if len(units[0]) == 1:
            return sum(row[0] for row in units)
        total = 0
        mn1 = mn2 = float("inf")
        for row in units:
            m1, m2 = top2(row)
            total += m2
            mn1 = min(mn1, m1)
            mn2 = min(mn2, m2)
        return total-mn2+mn1
