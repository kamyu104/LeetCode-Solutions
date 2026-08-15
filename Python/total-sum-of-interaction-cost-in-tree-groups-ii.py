# Time:  O(nlogn)
# Space: O(n)

import collections


# dfs, small-to-large merging
class Solution(object):
    def interactionCosts(self, n, edges, group):
        """
        :type n: int
        :type edges: List[List[int]]
        :type group: List[int]
        :rtype: int
        """
        def iter_dfs():
            order = []
            stk = [(0, -1)]
            while stk:
                u, p = stk.pop()
                order.append(u)
                for v in adj[u]:
                    if v == p:
                        continue
                    stk.append((v, u))
            return order

        def count(g, c):
            return c*(total[g]-c)

        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        total = [0]*n
        for g in group:
            total[g-1] += 1
        cnt = [collections.defaultdict(int) for _ in xrange(n)]
        cnt2 = [0]*n
        result = 0
        for u in reversed(iter_dfs()):
            cnt[u][group[u]-1] = 1
            cnt2[u] = count(group[u]-1, cnt[u][group[u]-1])
            for v in adj[u]:
                if not cnt[v]:
                    continue
                if len(cnt[u]) < len(cnt[v]):
                    cnt[u], cnt[v] = cnt[v], cnt[u]
                    cnt2[u], cnt2[v] = cnt2[v], cnt2[u]
                for g, c in cnt[v].iteritems():
                    cnt2[u] -= count(g, cnt[u][g])
                    cnt[u][g] += c
                    cnt2[u] += count(g, cnt[u][g])
                cnt[v].clear()
            result += cnt2[u]
        return result
