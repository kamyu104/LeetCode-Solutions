# Time:  O(n)
# Space: O(n)

# graph, hash table, stack
class Solution(object):
    def countVisitedNodes(self, edges):
        """
        :type edges: List[int]
        :rtype: List[int]
        """
        def find_cycles(adj):
            result = [0]*len(adj)
            lookup = [0]*len(adj)
            stk = []  # added
            idx = 0
            for u in xrange(len(adj)):
                prev = idx
                while not lookup[u]:
                    idx += 1
                    lookup[u] = idx
                    stk.append(u)  # added
                    u = adj[u]
                if lookup[u] > prev:
                    l = idx-lookup[u]+1
                    for _ in xrange(l):  # added
                        result[stk.pop()] = l
                while stk:  # added
                    result[stk[-1]] = result[adj[stk[-1]]]+1
                    stk.pop()
            return result
        
        return find_cycles(edges)
