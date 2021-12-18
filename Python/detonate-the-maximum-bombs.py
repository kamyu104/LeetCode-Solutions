# Time:  O(|V|^2 + |V| * |E|)
# Space: O(|V| + |E|)

# bfs solution
class Solution(object):
    def maximumDetonation(self, bombs):
        """
        :type bombs: List[List[int]]
        :rtype: int
        """        
        adj = [[] for _ in xrange(len(bombs))]
        for i, (xi, yi, ri) in enumerate(bombs):
            for j, (xj, yj, _) in enumerate(bombs):
                if j == i:
                    continue
                if (xi-xj)**2+(yi-yj)**2 <= ri**2:
                    adj[i].append(j)
        result = 0
        for i in xrange(len(bombs)):
            q = [i]
            lookup = {i}
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if v in lookup:
                            continue
                        lookup.add(v)
                        new_q.append(v)
                q = new_q
            result = max(result, len(lookup))
            if result == len(bombs):
                break
        return result


# Time:  O(|V|^2 + |V| * |E|)
# Space: O(|V| + |E|)
# dfs solution
class Solution2(object):
    def maximumDetonation(self, bombs):
        """
        :type bombs: List[List[int]]
        :rtype: int
        """        
        adj = [[] for _ in xrange(len(bombs))]
        for i, (xi, yi, ri) in enumerate(bombs):
            for j, (xj, yj, _) in enumerate(bombs):
                if j == i:
                    continue
                if (xi-xj)**2+(yi-yj)**2 <= ri**2:
                    adj[i].append(j)
        result = 0
        for i in xrange(len(bombs)):
            stk = [i]
            lookup = {i}
            while stk:
                u = stk.pop()
                for v in adj[u]:
                    if v in lookup:
                        continue
                    lookup.add(v)
                    stk.append(v)
            result = max(result, len(lookup))
            if result == len(bombs):
                break
        return result
