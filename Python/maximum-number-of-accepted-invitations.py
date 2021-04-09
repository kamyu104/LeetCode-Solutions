# Time:  O(|V| * |E|) = O(n * n^2) = O(n^3)
# Space: O(|E|) = O(n^2)

# we can use Hopcroft Karp algorithm to achieve |E|*sqrt(|V|) time or even better
# see: https://code.activestate.com/recipes/123641-hopcroft-karp-bipartite-matching/
#      https://en.wikipedia.org/wiki/Hopcroft%E2%80%93Karp_algorithm

class Solution(object):
    def maximumInvitations(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def augment(adj, u, lookup, match):
            for v in adj[u]:
                if v in lookup:
                    continue
                lookup.add(v)
                if v not in match or augment(adj, match[v], lookup, match):
                    match[v] = u  # greedily match
                    return True
            return False
    
        def max_bipartite_matching(adj, U):
            match = {}
            for i in xrange(U):
                if i not in match:
                    augment(adj, i, set(), match)
            return len(match)
        
        U, V = len(grid), len(grid[0])
        adj = [[] for _ in xrange(U+V)]
        for i in xrange(U):
            for j in xrange(V):
                if not grid[i][j]:
                    continue
                adj[i].append(U+j)  # use U+j to avoid conflicted node_id with i
                adj[U+j].append(i)
        return  max_bipartite_matching(adj, U)
