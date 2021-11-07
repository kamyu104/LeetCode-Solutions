# Time:  O(|V| + |E| + 4^(maxTime/min(edges))) = O(|V| + |E| + 4^10)
# Space: O(|V| + |E| + maxTime/min(edges)) = O(|V| + |E| + 10)

class Solution(object):
    def maximalPathQuality(self, values, edges, maxTime):
        """
        :type values: List[int]
        :type edges: List[List[int]]
        :type maxTime: int
        :rtype: int
        """
        def iter_dfs(adj):
            lookup = [0]*len(adj)
            result = 0
            stk = [(1, (0, maxTime, 0))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    u, time, total = args
                    lookup[u] += 1
                    if lookup[u] == 1:
                        total += values[u]
                    if not u:
                        result = max(result, total)
                    stk.append((2, (u,)))
                    for v, t in reversed(adj[u]):
                        if time >= t:
                            stk.append((1, (v, time-t, total)))
                elif step == 2:
                    u = args[0]
                    lookup[u] -= 1
            return result

        adj = [[] for _ in xrange(len(values))]
        for u, v, t in edges:
            adj[u].append((v, t))
            adj[v].append((u, t))
        return iter_dfs(adj)


# Time:  O(|V| + |E| + 4^(maxTime/min(edges))) = O(|V| + |E| + 4^10)
# Space: O(|V| + |E| + maxTime/min(edges)) = O(|V| + |E| + 10)
class Solution2(object):
    def maximalPathQuality(self, values, edges, maxTime):
        """
        :type values: List[int]
        :type edges: List[List[int]]
        :type maxTime: int
        :rtype: int
        """
        def dfs(values, adj, u, time, total, lookup, result):
            lookup[u] += 1
            if lookup[u] == 1:
                total += values[u]
            if not u:
                result[0] = max(result[0], total)
            for v, t in adj[u]:
                if time >= t:
                    dfs(values, adj, v, time-t, total, lookup, result)
            lookup[u] -= 1

        adj = [[] for _ in xrange(len(values))]
        for u, v, t in edges:
            adj[u].append((v, t))
            adj[v].append((u, t))
        result = [0]
        dfs(values, adj, 0, maxTime, 0, [0]*len(adj), result)
        return result[0]
