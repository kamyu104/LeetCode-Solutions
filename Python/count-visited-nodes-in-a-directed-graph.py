# Time:  O(n)
# Space: O(n)

# graph, prefix sum, two pointers, sliding window
class Solution(object):
    def countVisitedNodes(self, edges):
        """
        :type edges: List[int]
        :rtype: List[int]
        """
        def find_cycles(adj):
            result = [0]*len(adj)
            lookup = [0]*len(adj)
            lookup2 = [0]*len(adj)  # added
            idx = 0
            for u in xrange(len(adj)):
                prev = idx
                while not lookup[u]:
                    idx += 1
                    lookup[u] = idx
                    lookup2[idx-1] = u  # added
                    u = adj[u]
                if lookup[u] > prev:
                    l = idx-lookup[u]+1
                    for _ in xrange(l):  # added
                        result[u] = l
                        u = adj[u]
                for i in reversed(xrange(prev, lookup[u]-1 if lookup[u] > prev else idx)):  # added
                    result[lookup2[i]] = result[adj[lookup2[i]]]+1
            return result
        
        return find_cycles(edges)
