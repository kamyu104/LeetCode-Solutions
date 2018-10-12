# Time:  O(n)
# Space: O(n)

class Solution(object):
    def findContestMatch(self, n):
        """
        :type n: int
        :rtype: str
        """
        matches = map(str, range(1, n+1))
        while len(matches)/2:
            matches = ["({},{})".format(matches[i], matches[-i-1]) for i in xrange(len(matches)/2)]
        return matches[0]


