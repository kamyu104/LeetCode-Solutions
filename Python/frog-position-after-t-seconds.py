# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def frogPosition(self, n, edges, t, target):
        """
        :type n: int
        :type edges: List[List[int]]
        :type t: int
        :type target: int
        :rtype: float
        """        
        def dfs(G, target, t, node, parent):
            if not t or not (len(G[node])-(parent != 0)):
                return float(node == target)
            result = sum(dfs(G, target, t-1, child, node)
                         for child in G[node] if child != parent)
            return result/(len(G[node])-(parent != 0))
        
        G = collections.defaultdict(list)
        for u, v in edges:
            G[u].append(v)
            G[v].append(u)
        return dfs(G, target, t, 1, 0)
