# Time:  O(nlogn + mlogm)
# Space: O(n + m)

# dfs, centroid decomposition, prefix sum
class Solution(object):
    def maxTargetNodes(self, edges1, edges2, k):
        """
        :type edges1: List[List[int]]
        :type edges2: List[List[int]]
        :type k: int
        :rtype: List[int]
        """
        def centroid_decomposition(adj, k):
            def dfs(u):
                # https://usaco.guide/plat/centroid
                def find_subtree_size(u, p):
                    sizes[u] = 1
                    for v in adj[u]:
                        if v == p or lookup[v]:
                            continue
                        sizes[u] += find_subtree_size(v, u)
                    return sizes[u]

                def find_centroid(u, p):
                    for v in adj[u]:
                        if v == p or lookup[v]:
                            continue
                        if sizes[v]*2 > n:
                            return find_centroid(v, u)
                    return u

                def count(u, p, d):
                    if d > k:
                        return
                    if d-1 == len(cnt):
                        cnt.append(0)
                    cnt[d-1] += 1
                    for v in adj[u]:
                        if v == p or lookup[v]:
                            continue
                        count(v, u, d+1)

                def update(u, p, d):
                    if d > k:
                        return
                    result[u] += total[min(k-d, len(total)-1)]-curr[min(k-d, len(curr)-1)]
                    for v in adj[u]:
                        if v == p or lookup[v]:
                            continue
                        update(v, u, d+1)

                find_subtree_size(u, -1)
                n = sizes[u]
                u = find_centroid(u, -1)
                lookup[u] = True
                max_d = 0
                for v in adj[u]:
                    if lookup[v]:
                        continue
                    cnt = []
                    count(v, u, 0+1)
                    prefix[v].append(0)
                    for d in xrange(len(cnt)):
                        prefix[v].append(prefix[v][-1]+cnt[d])
                    max_d = max(max_d, len(cnt))
                total = [1]*(max_d+1)
                for v in adj[u]:
                    if lookup[v]:
                        continue
                    for d in xrange(len(total)):
                        total[d] += prefix[v][min(d, len(prefix[v])-1)]
                result[u] += total[min(k, len(total)-1)]
                for v in adj[u]:
                    if lookup[v]:
                        continue
                    curr, prefix[v] = prefix[v], []
                    update(v, u, 0+1)
                for v in adj[u]:
                    if lookup[v]:
                        continue
                    dfs(v)

            result = [0]*len(adj)
            sizes = [0]*len(adj)
            lookup = [False]*len(adj)
            prefix = [[] for _ in xrange(len(adj))]
            if k >= 0:
                dfs(0)
            return result

        def find_adj(edges):
            adj = [[] for _ in xrange(len(edges)+1)]
            for u, v in edges:
                adj[u].append(v)
                adj[v].append(u)
            return adj

        adj2 = find_adj(edges2)
        mx = max(centroid_decomposition(adj2, k-1))
        adj1 = find_adj(edges1)
        return [mx+x for x in centroid_decomposition(adj1, k)]


# Time:  O((n + m) * k)
# Space: O((n + m) * k)
# dfs, tree dp
class Solution2(object):
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
                dp[u][0] += 1
                for v in adj[u]:
                    if v == p:
                        continue
                    for d in xrange(k):
                        dp[u][d+1] += dp[v][d]
            
            def dfs2(u, p, curr):
                def update(v, u, curr):
                    new_curr = [0]*len(curr)
                    for d in xrange(len(curr)-1):
                        new_curr[d+1] = curr[d]+(dp[u][d]-(dp[v][d-1] if d-1 >= 0 else 0))
                    return new_curr

                for v in adj[u]:
                    if v == p:
                        continue
                    dfs2(v, u, update(v, u, curr))
                result[u] = sum(dp[u][i]+curr[i] for i in xrange(len(curr)))

            result = [0]*len(adj)
            k = min(k, len(adj)-1)
            if k == -1:
                return result
            dp = [[0]*(k+1) for _ in xrange(len(adj))]
            dfs1(0, -1)
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
class Solution3(object):
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
