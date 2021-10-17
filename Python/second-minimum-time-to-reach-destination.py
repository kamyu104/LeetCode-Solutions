# Time:  O(|V| + |E|) = O(|E|) since graph is connected, O(|E|) >= O(|V|) 
# Space: O(|V| + |E|) = O(|E|)

class Solution(object):
    def secondMinimum(self, n, edges, time, change):
        """
        :type n: int
        :type edges: List[List[int]]
        :type time: int
        :type change: int
        :rtype: int
        """
        # Template:
        # https://github.com/kamyu104/LeetCode-Solutions/blob/master/Python/find-if-path-exists-in-graph.py
        def bi_bfs(adj, start, target):
            left, right = {start}, {target}
            lookup = set()
            result = steps = 0
            while left and (not result or result+2 > steps):  # modified
                for u in left:
                    lookup.add(u)
                new_left = set()
                for u in left: 
                    if u in right:
                        if not result:  # modified
                            result = steps
                        elif result < steps:  # modifeid
                            return result+1
                    for v in adj[u]:
                        if v in lookup:
                            continue
                        new_left.add(v)
                left = new_left
                steps += 1
                if len(left) > len(right): 
                    left, right = right, left
            return result+2  # modified

        def calc_time(time, change, dist):
            result = 0
            for _ in xrange(dist):
                if result//change%2:
                    result = (result//change+1)*change
                result += time
            return result

        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u-1].append(v-1)
            adj[v-1].append(u-1)
        return calc_time(time, change, bi_bfs(adj, 0, n-1))


# Time:  O(|V| + |E|) = O(|E|) since graph is connected, O(|E|) >= O(|V|) 
# Space: O(|V| + |E|) = O(|E|)
class Solution2(object):
    def secondMinimum(self, n, edges, time, change):
        """
        :type n: int
        :type edges: List[List[int]]
        :type time: int
        :type change: int
        :rtype: int
        """
        INF = float("inf")
        def bfs(adj, start):
            q = [start]
            dist = [INF]*len(adj)
            dist[start] = 0
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if dist[v] != INF:
                            continue
                        dist[v] = dist[u]+1
                        new_q.append(v)
                q = new_q
            return dist

        def calc_time(time, change, dist):
            result = 0
            for _ in xrange(dist):
                if result//change%2:
                    result = (result//change+1)*change
                result += time
            return result

        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u-1].append(v-1)
            adj[v-1].append(u-1)
        dist_to_end, dist_to_start = bfs(adj, 0), bfs(adj, n-1)

        dist = dist_to_end[n-1]+2  # always exists
        for i in xrange(n):  # case of detour
            if dist_to_end[i]+dist_to_start[i] == dist_to_end[n-1]:
                continue
            dist = min(dist, dist_to_end[i]+dist_to_start[i])  # find second min
            if dist == dist_to_end[n-1]+1:
                break
        return calc_time(time, change, dist)
