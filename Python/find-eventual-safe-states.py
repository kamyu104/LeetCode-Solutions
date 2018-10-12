# Time:  O(|V| + |E|)
# Space: O(|V|)

import collections


class Solution(object):
    def eventualSafeNodes(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[int]
        """
        WHITE, GRAY, BLACK = 0, 1, 2

        def dfs(graph, node, lookup):
            if lookup[node] != WHITE:
                return lookup[node] == BLACK
            lookup[node] = GRAY
            for child in graph[node]:
                if lookup[child] == BLACK:
                    continue
                if lookup[child] == GRAY or \
                   not dfs(graph, child, lookup):
                    return False
            lookup[node] = BLACK
            return True

        lookup = collections.defaultdict(int)
        return filter(lambda node: dfs(graph, node, lookup), xrange(len(graph)))

