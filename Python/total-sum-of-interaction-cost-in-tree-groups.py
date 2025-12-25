# Time:  O(n * g)
# Space: O(n * g)

# iterative dfs
class Solution(object):
    def interactionCosts(self, n, edges, group):
        """
        :type n: int
        :type edges: List[List[int]]
        :type group: List[int]
        :rtype: int
        """
        def iter_dfs():
            result, parent = [], [-2]*len(adj)
            parent[0] = -1
            stk = [0]
            while stk:
                u = stk.pop()
                result.append(u)
                for v in reversed(adj[u]):
                    if parent[v] != -2:
                        continue
                    parent[v] = u
                    stk.append(v)
            return result, parent

        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        mx = max(group)
        total = [0]*mx
        for x in group:
            total[x-1] += 1
        result = 0
        order, parent = iter_dfs()
        cnt = [[0]*mx for _ in xrange(n)]
        for u in reversed(order):
            cnt[u][group[u]-1] += 1
            for v in adj[u]:
                if u != parent[v]:
                    continue
                for k in xrange(len(cnt[v])):
                    result += cnt[v][k]*(total[k]-cnt[v][k])
                    cnt[u][k] += cnt[v][k]
        return result


# Time:  O(nlogn)
# Space: O(n)
import collections


# iterative dfs, small-to-large merging
class Solution2(object):
    def interactionCosts(self, n, edges, group):
        """
        :type n: int
        :type edges: List[List[int]]
        :type group: List[int]
        :rtype: int
        """
        def iter_dfs():
            result, parent = [], [-2]*len(adj)
            parent[0] = -1
            stk = [0]
            while stk:
                u = stk.pop()
                result.append(u)
                for v in reversed(adj[u]):
                    if parent[v] != -2:
                        continue
                    parent[v] = u
                    stk.append(v)
            return result, parent

        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        total = collections.defaultdict(int)
        for x in group:
            total[x] += 1
        result = 0
        order, parent = iter_dfs()
        cnt = [collections.defaultdict(int) for _ in xrange(n)]
        for u in reversed(order):
            cnt[u][group[u]] += 1
            for v in adj[u]:
                if u != parent[v]:
                    continue
                for k, c in cnt[v].iteritems():
                    result += c*(total[k]-c)
                if len(cnt[v]) > len(cnt[u]):
                    cnt[u], cnt[v] = cnt[v], cnt[u]
                for k, c in cnt[v].iteritems():
                    cnt[u][k] += c
                cnt[v].clear()
        return result


# Time:  O(nlogn)
# Space: O(n)
import collections


# dfs, small-to-large merging
class Solution3(object):
    def interactionCosts(self, n, edges, group):
        """
        :type n: int
        :type edges: List[List[int]]
        :type group: List[int]
        :rtype: int
        """
        def dfs(u, p):
            cnt = collections.defaultdict(int)
            cnt[group[u]] += 1
            for v in adj[u]:
                if v == p:
                    continue
                new_cnt = dfs(v, u)
                for k, c in new_cnt.iteritems():
                    result[0] += c*(total[k]-c)
                if len(new_cnt) > len(cnt):
                    cnt, new_cnt = new_cnt, cnt
                for k, c in new_cnt.iteritems():
                    cnt[k] += c
            return cnt

        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        total = collections.defaultdict(int)
        for x in group:
            total[x] += 1
        result = [0]
        dfs(0, -1)
        return result[0]
