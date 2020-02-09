# Time:  O(m * n * sqrt(m * n))
# Space: O(m * n)

# the problem is the same as google codejam 2008 round 3 problem C
# https://github.com/kamyu104/GoogleCodeJam-2008/blob/master/Round%203/no_cheating.py

import collections


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
        
        for v in unmatched: recurse(v)


# Hopcroft-Karp bipartite matching
class Solution(object):
    def maxStudents(self, seats):
        """
        :type seats: List[List[str]]
        :rtype: int
        """
        directions = [(-1, -1), (0, -1), (1, -1), (-1, 1), (0, 1), (1, 1)]
        E, count = collections.defaultdict(list), 0
        for i in xrange(len(seats)):
            for j in xrange(len(seats[0])):
                if seats[i][j] != '.':
                    continue
                count += 1
                if j%2:
                    continue
                for dx, dy in directions:
                    ni, nj = i+dx, j+dy
                    if 0 <= ni < len(seats) and \
                       0 <= nj < len(seats[0]) and \
                       seats[ni][nj] == '.':
                        E[i*len(seats[0])+j].append(ni*len(seats[0])+nj)
        return count-len(bipartiteMatch(E)[0])


# Time:  O(|V| * |E|) = O(m^2 * n^2)
# Space: O(|V| + |E|) = O(m * n)
# Hungarian bipartite matching
class Solution2(object):
    def maxStudents(self, seats):
        """
        :type seats: List[List[str]]
        :rtype: int
        """
        directions = [(-1, -1), (0, -1), (1, -1), (-1, 1), (0, 1), (1, 1)]
        def dfs(seats, e, lookup, matching):
            i, j = e
            for dx, dy in directions:
                ni, nj = i+dx, j+dy
                if 0 <= ni < len(seats) and 0 <= nj < len(seats[0]) and \
                    seats[ni][nj] == '.' and not lookup[ni][nj]:
                    lookup[ni][nj] = True
                    if matching[ni][nj] == -1 or dfs(seats, matching[ni][nj], lookup, matching):
                        matching[ni][nj] = e
                        return True
            return False
        
        def Hungarian(seats):
            result = 0
            matching = [[-1]*len(seats[0]) for _ in xrange(len(seats))]
            for i in xrange(len(seats)):
                for j in xrange(0, len(seats[0]), 2):
                    if seats[i][j] != '.':
                        continue
                    lookup = [[False]*len(seats[0]) for _ in xrange(len(seats))]
                    if dfs(seats, (i, j), lookup, matching):
                        result += 1
            return result
          
        count = 0
        for i in xrange(len(seats)):
            for j in xrange(len(seats[0])):
                if seats[i][j] == '.':
                    count += 1
        return count-Hungarian(seats)


# Time:  O(m * 2^n * 2^n) = O(m * 4^n)
# Space: O(2^n)
# dp solution
class Solution3(object):
    def maxStudents(self, seats):
        """
        :type seats: List[List[str]]
        :rtype: int
        """
        def popcount(n):
            result = 0
            while n:
                n &= n - 1
                result += 1
            return result
        
        dp = {0: 0}
        for row in seats:
            invalid_mask = sum(1 << c for c, v in enumerate(row) if v == '#')
            new_dp = {}
            for mask1, v1 in dp.iteritems():
                for mask2 in xrange(1 << len(seats[0])):
                    if (mask2 & invalid_mask) or \
                       (mask2 & (mask1 << 1)) or (mask2 & (mask1 >> 1)) or \
                       (mask2 & (mask2 << 1)) or (mask2 & (mask2 >> 1)):
                        continue
                    new_dp[mask2] = max(new_dp.get(mask2, 0), v1+popcount(mask2))
            dp = new_dp
        return max(dp.itervalues()) if dp else 0
