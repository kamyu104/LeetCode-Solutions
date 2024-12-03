# Time:  O((n + m) * k)
# Space: O((n + m) * k)

# dfs, tree dp
class Solution(object):
    def maxTargetNodes(self, edges1, edges2, k):
        """
        :type edges1: List[List[int]]
        :type edges2: List[List[int]]
        :type k: int
        :rtype: List[int]
        """
        def tree_dp(adj, k):
            def dfs1(u, p):
                for v in adj[u]:
                    if v == p:
                        continue
                    dfs1(v, u)
                if 0 < len(dp[u]):
                    dp[u][0] += 1
                for v in adj[u]:
                    if v == p:
                        continue
                    for d in xrange(k):
                        dp[u][d+1] += dp[v][d]
            
            def dfs2(u, p, curr):
                def update(v, u, p, curr):
                    new_curr = [0]*len(curr)
                    for d in xrange(len(curr)-1):
                        new_curr[d+1] = curr[d]
                    for w in adj[u]:
                        if w == p:
                            continue
                        if w == v: 
                            if 1 < len(new_curr):
                                new_curr[1] += 1
                            continue
                        for d in xrange(len(new_curr)-2):
                            new_curr[d+2] += dp[w][d]
                    return new_curr

                for v in adj[u]:
                    if v == p:
                        continue
                    dfs2(v, u, update(v, u, p, curr))
                result[u] = sum(dp[u][i]+curr[i] for i in xrange(len(curr)))

            k = min(k, len(adj)-1)
            dp = [[0]*(k+1) for _ in xrange(len(adj))]
            dfs1(0, -1)
            result = [0]*len(adj)
            dfs2(0, -1, [0]*(k+1))
            return result

        def find_adj(edges):
            adj = [[] for _ in xrange(len(edges)+1)]
            for u, v in edges:
                adj[u].append(v)
                adj[v].append(u)
            return adj
        
        adj2 = find_adj(edges2)
        mx = max(tree_dp(adj2, k-1))
        adj1 = find_adj(edges1)
        return [mx+x for x in tree_dp(adj1, k)]


# Time:  O(n^2 + m^2)
# Space: O(n + m)
# brute force, bfs
class Solution2(object):
    def maxTargetNodes(self, edges1, edges2, k):
        """
        :type edges1: List[List[int]]
        :type edges2: List[List[int]]
        :type k: int
        :rtype: List[int]
        """
        def bfs(u, adj, k):
            result = 0
            q = [(u, -1)]
            while q:
                if k == -1:
                    break
                k -= 1
                new_q = []
                result += len(q)
                for u, p in q:
                    for v in adj[u]:
                        if v == p:
                            continue
                        new_q.append((v, u))
                q = new_q
            return result
    
        def find_adj(edges):
            adj = [[] for _ in xrange(len(edges)+1)]
            for u, v in edges:
                adj[u].append(v)
                adj[v].append(u)
            return adj

        adj2 = find_adj(edges2)
        mx = max(bfs(u, adj2, k-1) for u in xrange(len(adj2)))
        adj1 = find_adj(edges1)
        return [mx+bfs(u, adj1, k) for u in xrange(len(adj1))]
