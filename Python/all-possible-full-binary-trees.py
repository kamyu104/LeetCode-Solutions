# Time:  O(n * 4^n / n^(3/2)) ~= Catalan numbers
# Space: O(n * 4^n / n^(3/2)) ~= Catalan numbers

# A full binary tree is a binary tree where each node has exactly 0 or 2 children.
#
# Return a list of all possible full binary trees with N nodes.
# Each element of the answer is the root node of one possible tree.
#
# Each node of each tree in the answer must have node.val = 0.
#
# You may return the final list of trees in any order.
#
# Example 1:
#
# Input: 7
# Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],
#          [0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
# Explanation:
#
# Note:
# - 1 <= N <= 20

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def __init__(self):
        self.__memo = {1: [TreeNode(0)]}
    
    def allPossibleFBT(self, N):
        """
        :type N: int
        :rtype: List[TreeNode]
        """
        if N % 2 == 0:
            return []

        if N not in self.__memo:
            result = []
            for i in xrange(N):
                for left in self.allPossibleFBT(i):
                    for right in self.allPossibleFBT(N-1-i):
                        node = TreeNode(0)
                        node.left = left
                        node.right = right
                        result.append(node)
            self.__memo[N] = result

        return self.__memo[N]
 
