# Time:  O(n)
# Space: O(n)

class Solution(object):
    def isPathCrossing(self, path):
        """
        :type path: str
        :rtype: bool
        """
        x = y = 0
        lookup = {(0, 0)}
        for c in path:
            if c == 'E':
                x += 1
            elif c == 'W':
                x -= 1
            elif c == 'N':
                y += 1
            elif c == 'S':
                y -= 1
            if (x, y) in lookup:
                return True
            lookup.add((x, y))
        return False
