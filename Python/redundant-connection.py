# Time:  O(nlog*n) ~= O(n), n is the length of the positions
# Space: O(n)

# We are given a "tree" in the form of a 2D-array, with distinct values for each node.
#
# In the given 2D-array, each element pair [u, v] represents that v is a child of u in the tree.
#
# We can remove exactly one redundant pair in this "tree" to make the result a (rooted) tree.
#
# You need to find and output such a pair. If there are multiple answers for this question,
# output the one appearing last in the 2D-array. There is always at least one answer.
#
# Example 1:
# Input: [[1,2], [1,3], [2,3]]
# Output: [2,3]
# Explanation: Original tree will be like this:
#   1
#  / \
# 2 - 3
#
# Example 2:
# Input: [[1,2], [1,3], [3,1]]
# Output: [3,1]
# Explanation: Original tree will be like this:
#   1
#  / \\
# 2   3
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
        if x_root == y_root:
            return False
        self.set[min(x_root, y_root)] = max(x_root, y_root)
        self.count -= 1
        return True


class Solution(object):
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        union_find = UnionFind(len(edges)+1)
        for edge in edges:
            if not union_find.union_set(*edge):
                return edge
        return []
        
