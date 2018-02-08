# Time:  O(n)
# Space: O(1)

class Solution(object):
    def canTransform(self, start, end):
        """
        :type start: str
        :type end: str
        :rtype: bool
        """
        N = len(start)
        i, j = 0, 0
        while i < N and j < N:
            while i < N and start[i] == 'X':
                i += 1
            while j < N and end[j] == 'X':
                j += 1
            if (i < N) != (j < N):
                return False
            elif i < N and j < N:
                if start[i] != end[j] or \
                   (start[i] == 'L' and i < j) or \
                   (start[i] == 'R' and i > j):
                    return False
            i += 1
            j += 1
        return True
