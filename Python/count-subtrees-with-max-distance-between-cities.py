# Time:  O(n^5)
# Space: O(n^3)

import collections


class Solution(object):
    def countSubgraphsForEachDiameter(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        def dfs(n, adj, curr, parent, lookup, count, dp):
            children = []
            for child in adj[curr]:
                if child == parent or lookup[child]:
                    continue
                dfs(n, adj, child, curr, lookup, count, dp)
                children.append(child)
            for child in children:
                new_dp_curr = [row[:] for row in dp[curr]];
                for d in xrange(count[child]):
                    for max_d in xrange(count[child]):
                        new_dp_curr[d+1][max(max_d, d+1)] += dp[child][d][max_d]
                for curr_d in xrange(count[curr]):
                    for curr_max_d in xrange(count[curr]):
                        if not dp[curr][curr_d][curr_max_d]:
                            continue
                        for child_d in xrange(count[child]):
                            for child_max_d in xrange(count[child]):
                                max_d = max(curr_max_d, child_max_d, curr_d+child_d+1)
                                if max_d < len(new_dp_curr[max(curr_d, child_d+1)]):
                                    new_dp_curr[max(curr_d, child_d+1)][max_d] += dp[curr][curr_d][curr_max_d]*dp[child][child_d][child_max_d]
                dp[curr] = new_dp_curr
                count[curr] += count[child]
            dp[curr][0][0] = 1

        adj = collections.defaultdict(list)
        for u, v in edges:
            u -= 1
            v -= 1
            adj[u].append(v)
            adj[v].append(u)
        lookup, result = [0 for _ in xrange(n)], [0 for _ in xrange(n-1)]
        for i in xrange(n):
            dp = [[[0]*n for _ in xrange(n)] for _ in xrange(n)]
            count = [1]*n
            dfs(n, adj, i, -1, lookup, count, dp)
            lookup[i] = 1
            for d in xrange(1, n):
                for max_d in xrange(1, n):
                    result[max_d-1] += dp[i][d][max_d]
        return result
    

# Time:  O(n * 2^n)
# Space: O(n)
import collections


class Solution2(object):
    def countSubgraphsForEachDiameter(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        def bfs(adj, node_set, start):
            q = collections.deque([(start, 0)])
            lookup = {start}
            u, d = None, None
            while q:
                u, d = q.popleft()
                for v in adj[u]:
                    if v not in node_set or v in lookup:
                        continue
                    lookup.add(v)     
                    q.append((v, d+1))
            return len(lookup) == len(node_set), u, d
        
        def max_distance(n, edges, adj, mask):
            node_set = set()
            base = 1
            for i in xrange(n):
                if mask & base:
                    node_set.add(i)
                base <<= 1
            is_valid, farthest, _ = bfs(adj, node_set, next(iter(node_set), None))
            return bfs(adj, node_set, farthest)[-1] if is_valid else 0

        adj = collections.defaultdict(list)
        for u, v in edges:
            u -= 1
            v -= 1
            adj[u].append(v)
            adj[v].append(u)
        result = [0 for _ in xrange(n-1)]
        for mask in xrange(1, 2**n):
            d = max_distance(n, edges, adj, mask)
            if d-1 >= 0:
                result[d-1] += 1
        return result
