# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        if n == 1:
            return [0]

        neighbors = collections.defaultdict(set)
        for u, v in edges:
            neighbors[u].add(v)
            neighbors[v].add(u)

        pre_level, unvisited = [], set()
        for i in xrange(n):
            if len(neighbors[i]) == 1:  # A leaf.
                pre_level.append(i)
            unvisited.add(i)

        # A graph can have 2 MHTs at most.
        # BFS from the leaves until the number
        # of the unvisited nodes is less than 3.
        while len(unvisited) > 2:
            cur_level = []
            for u in pre_level:
                unvisited.remove(u)
                for v in neighbors[u]:
                    if v in unvisited:
                        neighbors[v].remove(u)
                        if len(neighbors[v]) == 1:
                            cur_level.append(v)
            pre_level = cur_level

        return list(unvisited)

