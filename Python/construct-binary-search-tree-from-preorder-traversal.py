# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def bstFromPreorder(self, preorder):
        """
        :type preorder: List[int]
        :rtype: TreeNode
        """
        def bstFromPreorderHelper(preorder, left, right, index):
            if index[0] == len(preorder) or \
               preorder[index[0]] < left or \
               preorder[index[0]] > right:
                return None

            root = TreeNode(preorder[index[0]])
            index[0] += 1
            root.left = bstFromPreorderHelper(preorder, left, root.val, index)
            root.right = bstFromPreorderHelper(preorder, root.val, right, index)
            return root
        
        return bstFromPreorderHelper(preorder, float("-inf"), float("inf"), [0])
