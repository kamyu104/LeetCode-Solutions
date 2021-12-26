# Time:  O(m)
# Space: O(m)

import collections


class Solution(object):
    def executeInstructions(self, n, startPos, s):
        """
        :type n: int
        :type startPos: List[int]
        :type s: str
        :rtype: List[int]
        """
        directions = {'U':(-1, 0), 'R':(0, 1), 'D':(1, 0), 'L':(0, -1)}
        (x0, y0), (x, y) = startPos, (0, 0)
        result = range(len(s), 0, -1)
        lookup_x = collections.defaultdict(list)
        lookup_y = collections.defaultdict(list)
        lookup_x[x0-x].append(0)
        lookup_y[y0-y].append(0)
        for i, d in enumerate(s):
            dx, dy = directions[d]
            x, y = x+dx, y+dy
            for k in n-x, -x-1:
                if k not in lookup_x:
                    continue
                for j in lookup_x[k]:
                    result[j] = min(result[j], i-j)
                lookup_x[k] = []
            for k in n-y, -y-1:
                if k not in lookup_y:
                    continue
                for j in lookup_y[k]:
                    result[j] = min(result[j], i-j)
                lookup_y[k] = []
            lookup_x[x0-x].append(i+1)
            lookup_y[y0-y].append(i+1)
        return result
