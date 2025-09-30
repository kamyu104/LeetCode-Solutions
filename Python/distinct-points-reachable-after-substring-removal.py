# Time:  O(n)
# Space: O(n)

# hash table
class Solution(object):
    def distinctPoints(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        DIRECTIONS = {'U':(0, 1), 'D':(0, -1), 'L':(-1, 0), 'R':(1, 0)}
        x = y = 0
        lookup = {(x, y)}
        for i in xrange(k, len(s)):
            x += DIRECTIONS[s[i]][0]-DIRECTIONS[s[i-k]][0]
            y += DIRECTIONS[s[i]][1]-DIRECTIONS[s[i-k]][1]
            lookup.add((x, y))
        return len(lookup)
