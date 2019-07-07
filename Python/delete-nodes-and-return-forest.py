# Time:  O(n)
# Space: O(h + d), d is the number of to_delete

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

        
class Solution(object):
    def delNodes(self, root, to_delete):
        """
        :type root: TreeNode
        :type to_delete: List[int]
        :rtype: List[TreeNode]
        """
        def delNodesHelper(to_delete_set, root, is_root, result):
            if not root:
                return None
            is_deleted = root.val in to_delete_set
            if is_root and not is_deleted:
                result.append(root)
            root.left = delNodesHelper(to_delete_set, root.left, is_deleted, result)
            root.right = delNodesHelper(to_delete_set, root.right, is_deleted, result)
            return None if is_deleted else root
        
        result = []
        to_delete_set = set(to_delete)
        delNodesHelper(to_delete_set, root, True, result)
        return result
