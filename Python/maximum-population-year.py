# Time:  O(n)
# Space: O(1)

class Solution(object):
    def maximumPopulation(self, logs):
        """
        :type logs: List[List[int]]
        :rtype: int
        """
        MIN_YEAR, MAX_YEAR = 1950, 2050
        years = [0]*(MAX_YEAR-MIN_YEAR+1)
        for s, e in logs:
            years[s-MIN_YEAR] += 1
            years[e-MIN_YEAR] -= 1
        max_total = total = 0
        for i, cnt in enumerate(years):
            total += cnt
            if total > max_total:
                max_total = total
                result = i+MIN_YEAR
        return result
