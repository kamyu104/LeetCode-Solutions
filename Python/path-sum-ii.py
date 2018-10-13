# Time:  O(n)
# Space: O(h), h is height of binary tree

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    # @param root, a tree node
    # @param sum, an integer
    # @return a list of lists of integers
    def pathSum(self, root, sum):
        return self.pathSumRecu([], [], root, sum)


    def pathSumRecu(self, result, cur, root, sum):
        if root is None:
            return result

        if root.left is None and root.right is None and root.val == sum:
            result.append(cur + [root.val])
            return result

        cur.append(root.val)
        self.pathSumRecu(result, cur, root.left, sum - root.val)
        self.pathSumRecu(result, cur,root.right, sum - root.val)
        cur.pop()
        return result

