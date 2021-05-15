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
        result = 0
        for i in xrange(len(years)):
            if i:
                years[i] += years[i-1]
            if years[i] > years[result]:
                result = i
        return result+MIN_YEAR
