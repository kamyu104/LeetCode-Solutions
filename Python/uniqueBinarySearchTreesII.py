# Time:  O(4^n / n^(3/2)) ~= Catalan numbers
# Space: O(4^n / n^(3/2)) ~= Catalan numbers
#
# Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
# 
# For example,
# Given n = 3, your program should return all 5 unique BST's shown below.
# 
#    1         3     3      2      1
#     \       /     /      / \      \
#      3     2     1      1   3      2
#     /     /       \                 \
#    2     1         2                 3
#

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    
    def __repr__(self):
        if self:
            serial = []
            queue = [self]

            while queue:
                cur = queue[0]
                
                if cur:
                    serial.append(cur.val)
                    queue.append(cur.left)
                    queue.append(cur.right)
                else:
                    serial.append("#")
                
                queue = queue[1:]
                
            while serial[-1] == "#":
                serial.pop()
                
            return repr(serial)
                
        else:
            return None

class Solution:
    # @return a list of tree node
    def generateTrees(self, n):
        return self.generateTreesRecu(1, n)
    
    def generateTreesRecu(self, low, high):
        result = []
        if low > high:
            result.append(None)
        for i in xrange(low, high + 1):
            left = self.generateTreesRecu(low, i - 1)
            right = self.generateTreesRecu(i + 1, high)
            for j in left:
                for k in right:
                    cur = TreeNode(i)
                    cur.left = j
                    cur.right = k
                    result.append(cur)
        return result

if __name__ == "__main__":
    print Solution().generateTrees(3)