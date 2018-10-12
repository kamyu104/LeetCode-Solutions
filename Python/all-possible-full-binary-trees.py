# Time:  O(n * 4^n / n^(3/2)) ~= sum of Catalan numbers from 1 .. N
# Space: O(n * 4^n / n^(3/2)) ~= sum of Catalan numbers from 1 .. N

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
 

