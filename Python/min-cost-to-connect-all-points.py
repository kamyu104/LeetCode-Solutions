# Time:  O(n^2)
# Space: O(n)

class Solution(object):
    def minCostConnectPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        result, u = 0, 0  # we can start from any node as u
        dist = [float("inf")]*len(points)
        lookup = set()
        for _ in xrange(len(points)-1):
            x0, y0 = points[u]
            lookup.add(u)
            for v, (x, y) in enumerate(points):
                if v in lookup:
                    continue
                dist[v] = min(dist[v], abs(x-x0) + abs(y-y0))
            val, u = min((val, v) for v, val in enumerate(dist)) 
            dist[u] = float("inf")  # used
            result += val
        return result



# Time:  O(eloge) = O(n^2 * logn)
# Space: O(e) = O(n^2)
# kruskal's algorithm
class UnionFind(object):  # Time: O(n * α(n)), Space: O(n)
    def __init__(self, n):
        self.set = range(n)
        self.rank = [0]*n

    def find_set(self, x):
        stk = []
        while self.set[x] != x:  # path compression
            stk.append(x)
            x = self.set[x]
        while stk:
            self.set[stk.pop()] = x
        return x

    def union_set(self, x, y):
        x_root, y_root = map(self.find_set, (x, y))
        if x_root == y_root:
            return False
        if self.rank[x_root] < self.rank[y_root]:  # union by rank
            self.set[x_root] = y_root
        elif self.rank[x_root] > self.rank[y_root]:
            self.set[y_root] = x_root
        else:
            self.set[y_root] = x_root
            self.rank[x_root] += 1
        return True


class Solution2(object):
    def minCostConnectPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        edges = []
        for u in xrange(len(points)):
            for v in xrange(u+1, len(points)):
                edges.append((u, v, abs(points[v][0]-points[u][0]) + abs(points[v][1]-points[u][1])))
        edges.sort(key=lambda x: x[2])
        result = 0
        union_find = UnionFind(len(points))
        for u, v, val in edges:
            if union_find.union_set(u, v):
                result += val
        return result

