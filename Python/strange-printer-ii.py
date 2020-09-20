# Time:  O(c * m * n + e), c is the number of colors
#                        , e is the number of edges in adj, at most O(c^2)
# Space: O(e)

import collections


class Solution(object):
    def isPrintable(self, targetGrid):
        """
        :type targetGrid: List[List[int]]
        :rtype: bool
        """
        VISITING, VISITED = range(2)
        def has_cycle(adj, color, lookup):
            stk = [(1, color)]
            while stk:
                step, color = stk.pop()
                if step == 1:
                    lookup[color] = VISITING
                    stk.append((2, color))
                    for new_color in adj[color]:
                        if new_color in lookup:
                            if lookup[new_color] == VISITED:
                                continue
                            return True  # VISITING
                        stk.append((1, new_color))
                elif step == 2:
                    lookup[color] = VISITED
            return False
                    

        MAX_COLOR = 60
        adj = collections.defaultdict(set)
        for color in xrange(1, MAX_COLOR+1):
            min_r = len(targetGrid)
            min_c = len(targetGrid[0])
            max_r = -1
            max_c = -1
            for r in xrange(len(targetGrid)):
                for c in xrange(len(targetGrid[r])):
                    if targetGrid[r][c] == color:
                        min_r = min(min_r, r)
                        min_c = min(min_c, c)
                        max_r = max(max_r, r)
                        max_c = max(max_c, c)
            for r in xrange(min_r, max_r+1):
                for c in xrange(min_c, max_c+1):
                    if targetGrid[r][c] != color:
                        adj[color].add(targetGrid[r][c])

        lookup = {}
        for color in xrange(1, MAX_COLOR+1): 
            if color in lookup:
                continue
            if has_cycle(adj, color, lookup):
                return False
        return True
            
