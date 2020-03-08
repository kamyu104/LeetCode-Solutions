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
        def dfs(G, node, t, target, lookup):
            if not (len(G[node])-(node != ROOT)) or not t:
                return float(node == target)
            lookup.add(node)
            result = sum(dfs(G, child, t-1, target, lookup)
                         for child in G[node] if child not in lookup)
            return result/(len(G[node])-(node != ROOT))
        
        ROOT = 1
        G = collections.defaultdict(list)
        for u, v in edges:
            G[u].append(v)
            G[v].append(u)
        return dfs(G, ROOT, t, target, set())
