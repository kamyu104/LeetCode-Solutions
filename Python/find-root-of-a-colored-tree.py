# Time:  O(n)
# Space: O(n)

# graph
class Solution(object):
    def findColoredRoot(self, edges, colors):
        """
        :type edges: List[List[int]]
        :type colors: str
        :rtype: int
        """
        LOOKUP = {'R':0, 'B':1, 'W':2}
        in_degree = [0]*(len(edges)+1)
        out_degree = [0]*(len(edges)+1)
        for u, v in edges:
            x, y = LOOKUP[colors[u]], LOOKUP[colors[v]]
            if x == y:
                return -1
            if (x+1)%3 != y:
                u, v = v, u
            out_degree[u] += 1
            in_degree[v] += 1
        return in_degree.index(0) if max(out_degree) <= 2 and max(in_degree) <= 1 else -1
