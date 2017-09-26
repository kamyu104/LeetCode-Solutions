# Time:  O(nlog*n) ~= O(n), n is the length of the positions
# Space: O(n)

# In this problem, a rooted tree is a directed graph such that,
# there is exactly one node (the root) for
# which all other nodes are descendants of this node, plus every node has exactly one parent,
# except for the root node which has no parents.
#
# The given input is a directed graph that started as a rooted tree with N nodes
# (with distinct values 1, 2, ..., N), with one additional directed edge added.
# The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.
#
# The resulting graph is given as a 2D-array of edges.
# Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v,
# where u is a parent of child v.
#
# Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes.
# If there are multiple answers, return the answer that occurs last in the given 2D-array.
#
# Example 1:
# Input: [[1,2], [1,3], [2,3]]
# Output: [2,3]
# Explanation: The given directed graph will be like this:
#   1
#  / \
# v   v
# 2-->3
# Example 2:
# Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
# Output: [4,1]
# Explanation: The given directed graph will be like this:
# 5 <- 1 -> 2
#      ^    |
#      |    v
#      4 <- 3
# Note:
# The size of the input 2D-array will be between 3 and 1000.
# Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

class UnionFind(object):
    def __init__(self, n):
        self.set = range(n)
        self.count = n

    def find_set(self, x):
        if self.set[x] != x:
            self.set[x] = self.find_set(self.set[x])  # path compression.
        return self.set[x]

    def union_set(self, x, y):
        x_root, y_root = map(self.find_set, (x, y))
        if x_root == y_root or \
           y != y_root:  # more the one father
            return False
        self.set[y_root] = x_root
        self.count -= 1
        return True

    
class Solution(object):
    def findRedundantDirectedConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        union_find = UnionFind(len(edges)+1)
        for edge in edges:
            if not union_find.union_set(*edge):
                return edge
        return []
