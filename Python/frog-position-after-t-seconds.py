# Time:  O(n)
# Space: O(n)

import collections


# bfs solution with better precision
class Solution(object):
    def frogPosition(self, n, edges, t, target):
        """
        :type n: int
        :type edges: List[List[int]]
        :type t: int
        :type target: int
        :rtype: float
        """                
        G = collections.defaultdict(list)
        for u, v in edges:
            G[u].append(v)
            G[v].append(u)

        stk = [(t, 1, 0, 1)]
        while stk:
            new_stk = []
            while stk:
                t, node, parent, choices = stk.pop()
                if not t or not (len(G[node])-(parent != 0)):
                    if node == target:
                        return 1.0/choices
                    continue
                for child in G[node]:
                    if child == parent:
                        continue
                    new_stk.append((t-1, child, node,
                                    choices*(len(G[node])-(parent != 0))))
            stk = new_stk
        return 0.0


# Time:  O(n)
# Space: O(n)
# dfs solution with stack with better precision
class Solution2(object):
    def frogPosition(self, n, edges, t, target):
        """
        :type n: int
        :type edges: List[List[int]]
        :type t: int
        :type target: int
        :rtype: float
        """                
        G = collections.defaultdict(list)
        for u, v in edges:
            G[u].append(v)
            G[v].append(u)

        stk = [(t, 1, 0, 1)]
        while stk:
            t, node, parent, choices = stk.pop()
            if not t or not (len(G[node])-(parent != 0)):
                if node == target:
                    return 1.0/choices
                continue
            for child in G[node]:
                if child == parent:
                    continue
                stk.append((t-1, child, node,
                            choices*(len(G[node])-(parent != 0))))
        return 0.0


# Time:  O(n)
# Space: O(n)
# dfs solution with recursion with better precision
class Solution3(object):
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
                return int(node == target)
            result = 0
            for child in G[node]:
                if child == parent:
                    continue
                result = dfs(G, target, t-1, child, node)
                if result:
                    break
            return result*(len(G[node])-(parent != 0))
        
        G = collections.defaultdict(list)
        for u, v in edges:
            G[u].append(v)
            G[v].append(u)
        choices = dfs(G, target, t, 1, 0)
        return 1.0/choices if choices else 0.0


# Time:  O(n)
# Space: O(n)
# dfs solution with recursion
class Solution4(object):
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
            for child in G[node]:
                if child == parent:
                    continue
                result = dfs(G, target, t-1, child, node)
                if result:
                    break
            return result/(len(G[node])-(parent != 0))
        
        G = collections.defaultdict(list)
        for u, v in edges:
            G[u].append(v)
            G[v].append(u)
        return dfs(G, target, t, 1, 0)
