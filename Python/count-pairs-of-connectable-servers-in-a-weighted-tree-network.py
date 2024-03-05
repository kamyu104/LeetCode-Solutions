# Time:  O(n^2)
# Space: O(n)

# iterative dfs
class Solution(object):
    def countPairsOfConnectableServers(self, edges, signalSpeed):
        """
        :type edges: List[List[int]]
        :type signalSpeed: int
        :rtype: List[int]
        """
        def iter_dfs(u, p, dist):
            result = 0
            stk = [(u, p, dist)]
            while stk:
                u, p, dist = stk.pop()
                if dist%signalSpeed == 0:
                    result += 1
                for v, w in reversed(adj[u]):
                    if v == p:
                        continue
                    stk.append((v, u, dist+w))
            return result
        
        adj = [[] for _ in xrange(len(edges)+1)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))
        result = [0]*(len(edges)+1)
        for u in xrange(len(result)):
            curr = 0
            for v, w in adj[u]:
                cnt = iter_dfs(v, u, w)
                result[u] += curr*cnt
                curr += cnt
        return result


# Time:  O(n^2)
# Space: O(n)
# dfs
class Solution2(object):
    def countPairsOfConnectableServers(self, edges, signalSpeed):
        """
        :type edges: List[List[int]]
        :type signalSpeed: int
        :rtype: List[int]
        """
        def dfs(u, p, dist):
            cnt = 1 if dist%signalSpeed == 0 else 0
            for v, w in adj[u]:
                if v == p:
                    continue
                cnt += dfs(v, u, dist+w)
            return cnt
        
        adj = [[] for _ in xrange(len(edges)+1)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))
        result = [0]*(len(edges)+1)
        for u in xrange(len(result)):
            curr = 0
            for v, w in adj[u]:
                cnt = dfs(v, u, w)
                result[u] += curr*cnt
                curr += cnt
        return result


# Time:  O(n^2)
# Space: O(n)
# bfs
class Solution3(object):
    def countPairsOfConnectableServers(self, edges, signalSpeed):
        """
        :type edges: List[List[int]]
        :type signalSpeed: int
        :rtype: List[int]
        """
        def bfs(u, p, dist):
            result = 0
            q = [(u, p, dist)]
            while q:
                new_q = []
                for u, p, dist in q:
                    if dist%signalSpeed == 0:
                        result += 1
                    for v, w in adj[u]:
                        if v == p:
                            continue
                        new_q.append((v, u, dist+w))
                q = new_q
            return result
        
        adj = [[] for _ in xrange(len(edges)+1)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))
        result = [0]*(len(edges)+1)
        for u in xrange(len(result)):
            curr = 0
            for v, w in adj[u]:
                cnt = bfs(v, u, w)
                result[u] += curr*cnt
                curr += cnt
        return result
