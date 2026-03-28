# Time:  O(n^2)
# Space: O(n)

# bfs, iterative dfs
class Solution(object):
    def maxSum(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        def bfs():
            adj = [[]]
            vals = [root.val]
            q = [(root, -1)]
            while q:
                new_q = []
                for u, p in q:
                    vals.append(u.val)
                    adj.append([])
                    i = len(adj)-1
                    if p != -1:
                        adj[i].append(p)
                        adj[p].append(i)
                    for node in (u.left, u.right):
                        if not node:
                            continue
                        new_q.append((node, i))
                q = new_q
            return adj, vals

        def iter_dfs(u):
            result = float("-inf")
            total = 0
            lookup = set()
            stk = [(1, u, -1)]
            while stk:
                step, u, p = stk.pop()
                if step == 1:
                    if vals[u] in lookup:
                        continue
                    stk.append((2, u, p))
                    lookup.add(vals[u])
                    total += vals[u]
                    result = max(result, total)
                    for v in adj[u]:
                        if v == p:
                            continue
                        stk.append((1, v, u))
                elif step == 2:
                    total -= vals[u]
                    lookup.remove(vals[u])
            return result    

        adj, vals = bfs()
        return max(iter_dfs(u) for u in xrange(len(adj)))


# Time:  O(n^2)
# Space: O(n)
# dfs
class Solution2(object):
    def maxSum(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        def dfs1(u, p):
            vals.append(u.val)
            adj.append([])
            i = len(adj)-1
            if p != -1:
                adj[i].append(p)
                adj[p].append(i)
            for node in (u.left, u.right):
                if not node:
                    continue
                dfs1(node, i)
        
        def dfs2(u, p):
            if vals[u] in lookup:
                return float("-inf")
            lookup.add(vals[u])
            mx = 0
            for v in adj[u]:
                if v == p:
                    continue
                mx = max(mx, dfs2(v, u))
            lookup.remove(vals[u])
            return vals[u]+mx
            
        adj, vals = [], []
        dfs1(root, -1)
        lookup = set()
        return max(dfs2(u, -1) for u in xrange(len(adj)))
