# Time:  O(n)
# Space: O(n)

# For a undirected graph with tree characteristics, we can
# choose any node as the root. The result graph is then a
# rooted tree. Among all possible rooted trees, those with
# minimum height are called minimum height trees (MHTs).
# Given such a graph, write a function to find all the 
# MHTs and return a list of their root labels.
#
# Format
# The graph contains n nodes which are labeled from 0 to n - 1.
# You will be given the number n and a list of undirected
# edges (each edge is a pair of labels).
#
# You can assume that no duplicate edges will appear in edges.
# Since all edges are undirected, [0, 1] is the same as [1, 0]
# and thus will not appear together in edges.
#
# Example 1:
#
# Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
#
#         0
#         |
#         1
#        / \
#       2   3
# return [1]
#
# Example 2:
#
# Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
#
#      0  1  2
#       \ | /
#         3
#         |
#         4
#         |
#         5
# return [3, 4]
#
# Hint:
#
# How many MHTs can a graph have at most?
# Note:
#
# (1) According to the definition of tree on Wikipedia: 
#     "a tree is an undirected graph in which any two vertices 
#     are connected by exactly one path. In other words, 
#     any connected graph without simple cycles is a tree."
#
# (2) The height of a rooted tree is the number of edges on the 
#     longest downward path between the root and a leaf.

class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        if n == 1:
            return [0]
        neighbors = collections.defaultdict(list)
        degrees = collections.defaultdict(int)
        for u, v in edges:
            neighbors[u].append(v)
            neighbors[v].append(u)
            degrees[u] += 1
            degrees[v] += 1

        pre_level, unvisited = [], set(xrange(n))
        for i in xrange(n):
            if degrees[i] == 1:  # A leaf.
                pre_level.append(i)

        # A graph can have 2 MHTs at most.
        # BFS from the leaves until the number 
        # of the unvisited nodes is less than 3.
        while len(unvisited) > 2:
            this_level = []
            for u in pre_level:
                unvisited.remove(u)
                for v in neighbors[u]:
                    if v in unvisited: 
                        degrees[v] -= 1
                        if degrees[v] == 1:
                            this_level += [v]
            pre_level = this_level
    
        return list(unvisited)
