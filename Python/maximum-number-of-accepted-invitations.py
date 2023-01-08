# Time:  O(m * n * sqrt(m + n))
# Space: O(m * n)

from functools import partial

# Time:  O(E * sqrt(V))
# Space: O(V)
# Source code from http://code.activestate.com/recipes/123641-hopcroft-karp-bipartite-matching/
# Hopcroft-Karp bipartite max-cardinality matching and max independent set
# David Eppstein, UC Irvine, 27 Apr 2002
def bipartiteMatch(graph):
    '''Find maximum cardinality matching of a bipartite graph (U,V,E).
    The input format is a dictionary mapping members of U to a list
    of their neighbors in V.  The output is a triple (M,A,B) where M is a
    dictionary mapping members of V to their matches in U, A is the part
    of the maximum independent set in U, and B is the part of the MIS in V.
    The same object may occur in both U and V, and is treated as two
    distinct vertices if this happens.'''
    
    # initialize greedy matching (redundant, but faster than full search)
    matching = {}
    for u in graph:
        for v in graph[u]:
            if v not in matching:
                matching[v] = u
                break
    
    while 1:
        # structure residual graph into layers
        # pred[u] gives the neighbor in the previous layer for u in U
        # preds[v] gives a list of neighbors in the previous layer for v in V
        # unmatched gives a list of unmatched vertices in final layer of V,
        # and is also used as a flag value for pred[u] when u is in the first layer
        preds = {}
        unmatched = []
        pred = dict([(u,unmatched) for u in graph])
        for v in matching:
            del pred[matching[v]]
        layer = list(pred)
        
        # repeatedly extend layering structure by another pair of layers
        while layer and not unmatched:
            newLayer = {}
            for u in layer:
                for v in graph[u]:
                    if v not in preds:
                        newLayer.setdefault(v,[]).append(u)
            layer = []
            for v in newLayer:
                preds[v] = newLayer[v]
                if v in matching:
                    layer.append(matching[v])
                    pred[matching[v]] = v
                else:
                    unmatched.append(v)
        
        # did we finish layering without finding any alternating paths?
        if not unmatched:
            unlayered = {}
            for u in graph:
                for v in graph[u]:
                    if v not in preds:
                        unlayered[v] = None
            return (matching,list(pred),list(unlayered))

        # recursively search backward through layers to find alternating paths
        # recursion returns true if found path, false otherwise
        def recurse(v):
            if v in preds:
                L = preds[v]
                del preds[v]
                for u in L:
                    if u in pred:
                        pu = pred[u]
                        del pred[u]
                        if pu is unmatched or recurse(pu):
                            matching[v] = u
                            return 1
            return 0
        
        def recurse_iter(v):
            def divide(v):
                if v not in preds:
                    return
                L = preds[v]
                del preds[v]
                for u in L :
                    if u in pred and pred[u] is unmatched:  # early return
                        del pred[u]
                        matching[v] = u
                        ret[0] = True
                        return
                stk.append(partial(conquer, v, iter(L)))

            def conquer(v, it):
                for u in it:
                    if u not in pred:
                        continue
                    pu = pred[u]
                    del pred[u]
                    stk.append(partial(postprocess, v, u, it))
                    stk.append(partial(divide, pu))
                    return

            def postprocess(v, u, it):
                if not ret[0]:
                    stk.append(partial(conquer, v, it))
                    return
                matching[v] = u

            ret, stk = [False], []
            stk.append(partial(divide, v))
            while stk:
                stk.pop()()
            return ret[0]

        for v in unmatched: recurse_iter(v)


import collections


# Hopcroft-Karp bipartite matching
class Solution(object):
    def maximumInvitations(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        adj = collections.defaultdict(list)
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if not grid[i][j]:
                    continue
                adj[j].append(i)
        return len(bipartiteMatch(adj)[0])


# Time:  O(|V| * |E|) = O(min(m, n) * (m * n))
# Space: O(|V|) = O(min(m, n))
# Hungarian bipartite matching with less space
class Solution2(object):
    def maximumInvitations(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def augment(grid, u, lookup, match):
            for v in xrange(V):
                if not get_grid(u, v) or v in lookup:
                    continue
                lookup.add(v)
                if v not in match or augment(grid, match[v], lookup, match):
                    match[v] = u  # greedily match
                    return True
            return False
    
        def hungarian(grid):
            match = {}
            for i in xrange(U):
                augment(grid, i, set(), match)
            return len(match)

        U, V = min(len(grid), len(grid[0])), max(len(grid), len(grid[0]))
        get_grid = (lambda x, y: grid[x][y]) if len(grid) < len(grid[0]) else (lambda x, y: grid[y][x])
        return hungarian(grid)


# Time:  O(|V| * |E|) = O(min(m, n) * (m * n))
# Space: O(|E|) = O(m * n)
import collections


# Hungarian bipartite matching
class Solution3(object):
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
    
        def hungarian(adj):
            match = {}
            for i in adj.iterkeys():
                augment(adj, i, set(), match)
            return len(match)
        
        adj = collections.defaultdict(list)
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if not grid[i][j]:
                    continue
                if len(grid) < len(grid[0]):
                    adj[i].append(j)
                else:
                    adj[j].append(i)
        return hungarian(adj)
